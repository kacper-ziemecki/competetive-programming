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

int n,m,u,v,w,res=INT_MAX;
const int M = 1e4+1;
vector<int> edges[M];

struct DSU{
  vector<int> p,sajz;
  DSU(int n){
    p.resize(n);
    for(int i = 0; i < n; i++) p[i] = i;
    sajz.assign(n,1);
  }
  int findSet(int a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool same(int a, int b){ return findSet(a) == findSet(b); }
};

void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    edges[i] = {w,u,v};
  }
  sort(edges, edges+m);
  for(int i = 0; i+n-2 < m; i++){
    int cnt = 0, mn = INT_MAX, mx = INT_MIN;
    DSU dsu(n+1);
    for(int j = i; j < m; j++){
      if(!dsu.same(edges[j][1], edges[j][2])){
        cnt++;
        mn = min(mn, edges[j][0]);
        mx = max(mx, edges[j][0]);
        dsu.unionSet(edges[j][1], edges[j][2]);
      }
      if(cnt == n-1) break;
    }
    if(cnt == n-1) res = min(res, mx-mn);
    // dbg(i,mn,mx);
  }
  if(res == INT_MAX){
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << res << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../in.in", "r", stdin);
  freopen("../../../out.out", "w", stdout);
#endif

  solve();
}