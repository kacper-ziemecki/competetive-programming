#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m,k,l,r;
const int N = 1e5+1, Ai = 1e7+1, M = 1e5+1;
const int BLOCK = ceil(sqrt(N));
ll lista[N], cnt[Ai], ans[M];

struct Query{
  int l,r,idx;
  bool operator<(Query other) const{
    return make_pair(l / BLOCK, r) < make_pair(other.l / BLOCK, other.r);
  }
};

struct MO{
  ll cur_l,cur_r,res,usuniete;
  vector<ll> pref,cnt;
  MO(){
    cur_l = 1;
    cur_r = 0;
    res = 0;
    cnt.assign(Ai, 0);
    cnt[0] = 1;
    pref.resize(n+1);
    usuniete = 0;
    pref[0] = 0;
    pref[1] = lista[0];
    for(int i = 2; i < n+1; i++) pref[i] = pref[i-1]^lista[i-1];
    // for(auto el : pref) cout << el << ' ';
    // cout << endl;
  }
  void add_right(){
    cur_r++;
    res += cnt[pref[cur_r]^k];
    cnt[pref[cur_r]]++;
    // dbg(cur_l, cur_r, res);
  }
  void add_left(){
    cur_l--;
    usuniete = usuniete ^ lista[cur_l-1];
    // dbg(usuniete^k, cnt[usuniete^k]);
    res += cnt[usuniete^k];
    cnt[pref[cur_l-1]]++;
    // dbg("add_left",cur_l,cur_r,usuniete,res);
  }
  void remove_right(){
    cnt[pref[cur_r]]--;
    res -= cnt[pref[cur_r]^k];
    cur_r--;
  }
  void remove_left(){
    cnt[pref[cur_l-1]]--;
    res -= cnt[k^usuniete];
    usuniete = usuniete ^ lista[cur_l-1];
    cur_l++;
    // dbg(usuniete, k^usuniete);
    // dbg("remove_left",cur_l,cur_r,res);
  }
};




void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> lista[i];
  vector<Query> queries(m);
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    queries[i].l = l;
    queries[i].r = r;
    queries[i].idx = i;
  }
  sort(queries.begin(), queries.end());
  MO mo;
  for(int i = 0; i < m; i++){
    Query q = queries[i];
    while(mo.cur_r < q.r) mo.add_right();
    while(mo.cur_l > q.l) mo.add_left();
    while(mo.cur_l < q.l) mo.remove_left();
    while(mo.cur_r > q.r) mo.remove_right();
    // dbg(q.l, q.r);
    ans[q.idx] = mo.res;
  }
  for(int i = 0; i < m; i++) cout << ans[i] << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}