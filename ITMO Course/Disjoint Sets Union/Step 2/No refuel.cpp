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

int n,k,w,u,v,cnt,res=INT_MIN;
const int K = 4e5+1;
vector<int> edges[K];

struct DSU{
  vector<int> p,sajz;
  DSU(int n){
    p.resize(n+1);
    for(int i = 0; i <= n; i++) p[i] = i;
    sajz.assign(n+1, 1);
  }
  int findSet(int a){
    return (p[a] == a ? a : p[a] = findSet(p[a]));
  }
  void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool same(int a, int b){
    return findSet(a) == findSet(b);
  }
};

void solve(){
  cin >> n >> k;
  for(int i = 0; i < k; i++){
    cin >> u >> v >> w;
    edges[i] = {w,u,v};
  }
  sort(edges, edges+k);
  DSU dsu(n+1);
  for(int i = 0; i < k; i++){
    if(!dsu.same(edges[i][1], edges[i][2])){
      dsu.unionSet(edges[i][1], edges[i][2]);
      cnt++;
      res = max(res, edges[i][0]);
    }
    if(cnt == n-1) break;
  }
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