#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,k,res=0;
const int maxn = 1e5+1;
ll lista[maxn], dp[12][maxn];

struct SegTree{
  vector<ll> nodes;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    nodes.assign(ss<<1, 0);
  }
  void set(int idx, ll val, int x, int lx, int rx){
    if(rx < idx || idx < lx) return;
    if(lx == rx){
      nodes[x] += val;
      return;
    }
    int mid = (lx+rx)/2;
    set(idx,val,2*x+1,lx,mid);
    set(idx,val,2*x+2,mid+1,rx);
    nodes[x] = nodes[2*x+1] + nodes[2*x+2];
  }
  void set(int idx, ll val){
    set(idx,val,0,1,ss);
  }
  ll get(int l, int r, int x, int lx, int rx){
    if(l <= lx && rx <= r) return nodes[x];
    if(lx > r || rx < l) return 0;
    int mid = (lx+rx)/2;
    return get(l,r,2*x+1,lx,mid)+get(l,r,2*x+2,mid+1,rx);
  }
  ll get(int l, int r){
    return get(l,r,0,1,ss);
  }
};

void solve(){
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < n; i++) dp[0][i] = 1;
  for(int i = 1; i <= k; i++){
    SegTree segtree(n+1);
    for(int j = 0; j < n; j++){
      dp[i][j] = segtree.get(1,lista[j]-1);
      if(i == k) res += dp[i][j];
      // dbg(i,j,dp[i][j]);
      // for(auto el : segtree.nodes) cout << el << ' ';
      // cout << endl;
      segtree.set(lista[j],dp[i-1][j]);
    }
  }
  cout << (k == 0 ? n : res) << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  solve();
}