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

ll n,m,s,u,v,w;
const ll M = 1e5+1;
vector<ll> edges[M];

struct DSU{
  vector<ll> p,sajz;
  DSU(ll n){
    p.resize(n+1);
    for(ll i = 0; i <= n; i++) p[i] = i;
    sajz.assign(n+1, 1);
  }
  ll findSet(ll a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSet(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool same(ll a, ll b){
    return findSet(a) == findSet(b);
  }
};
void solve(){
 cin >> n >> m >> s;
 for(ll i = 0; i < m; i++){
  cin >> u >> v >> w;
  edges[i] = {w,u,v,i};
 }
 sort(edges,edges+m, greater<>());
 vector<pair<ll,ll>> rest;
 DSU dsu(n+1);
 for(ll i = 0; i < m; i++){
  if(!dsu.same(edges[i][1], edges[i][2])){
    dsu.unionSet(edges[i][1], edges[i][2]);
  } else{
    rest.pb(make_pair(edges[i][0], edges[i][3]));
  }
 }
  sort(rest.begin(), rest.end());
  ll suma=0;
  vector<ll> res;
  for(ll i = 0; i < rest.size(); i++){
    if(suma + rest[i].first <= s){
      suma += rest[i].first;
      res.pb(rest[i].second);
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for(auto el : res) cout << el+1 << ' ';
  cout << endl;
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