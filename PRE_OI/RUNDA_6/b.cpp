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

int n;
ll res = 0;
ll j,cnt;
vector<int> lista;

struct SegTree {

  int ss;
  vector<int> values;
  vector<vector<int>> prop;

  void init(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    values.assign(ss<<1, INT_MAX);
    prop.resize(ss<<1);
  }

  void propagate(int x){
    for(int p : prop[x]){
      if(values[x] > p) continue;
      else{ // nasz przedzial
        values[x]--;
        if(2*x+1 < (ss<<1)) prop[2*x+1].pb(p);
        if(2*x+2 < (ss<<1)) prop[2*x+2].pb(p);
      }
    }
    prop[x].clear();
  }

  void set(int i, int v, int x, int lx, int rx){
    propagate(x);
    if(lx > i || rx < i) return;
    if(rx == lx){
      values[x] = v;
      return;
    }
    int m = (lx+rx)/2;
    set(i, v, 2*x+1, lx, m);
    set(i, v, 2*x+2, m+1, rx);
    values[x] = min(values[2*x+1], values[2*x+2]);
  }

  void set(int i, int v){
    set(i,v,0,0,ss-1);
  }
  ll calc(int l, int r, int x, int lx, int rx){
    propagate(x);
    if(lx > r || l > rx) return INT_MAX;
    if(lx >= l && rx <= r) return values[x];
    int m = (lx+rx)/2;
    int s1 = calc(l, r, 2*x+1, lx, m);
    int s2 = calc(l, r, 2*x+2, m+1, rx);
    return min(s1,s2);
  }

  ll calc(int l, int r){
    return calc(l, r, 0, 0, ss-1);
  }
};

SegTree segtree;

void solve(){
  cin >> n;
  lista.resize(n);
  segtree.init(n+1);
  for(auto &el : lista) cin >> el;
  segtree.set(lista[n-1],n-1);
  for(int i = n-2; i >= 0; i--){

    int minimalny_idx = segtree.calc(lista[i], n);
    if(minimalny_idx == INT_MAX){ // nie ma wiekszego
      res += (n-2)-i;
      segtree.prop[0].pb(i-1);
    } else{
      res += minimalny_idx-i-1;
      segtree.prop[0].pb(i-1);
    }
  }
  cout << res << endl;
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