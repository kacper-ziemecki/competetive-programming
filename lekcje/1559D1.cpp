#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

class Dsu{
public:
  vector<ll> p,rank;
  Dsu(ll n){
    p.assign(n+1,0);
    rank.assign(n+1,1);
    for(ll i = 0; i < n+1; i++) p[i] = i;
  }
  Dsu(Dsu& disjointSet){
    p = disjointSet.p;
    rank = disjointSet.rank;
  }
  ll findSet(ll a){
    return (p[a] == a ? a : p[a] = findSet(p[a]));
  }
  bool canConnect(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    return a != b;
  }
  void unionSet(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(rank[a] < rank[b]) swap(a, b);
    rank[a] += rank[b];
    p[b] = a;
  }
};


void solve()
{
  ll n,m1,m2;
  cin >> n >> m1 >> m2;
  vector<pair<ll,ll>> edge1(m1), edge2(m2);
  ll u,v;
  for(ll i = 0; i < m1; i++){
    cin >> u >> v;
    edge1[i] = {u,v};
  }
  for(ll i = 0; i < m2; i++){
    cin >> u >> v;
    edge2[i] = {u,v};
  }
  Dsu connections1(n+1), connections2(n+1);
  for(auto el : edge1){
    connections1.unionSet(el.first,el.second);
  }
  for(auto el : edge2){
    connections2.unionSet(el.first,el.second);
  }
  vector<pair<ll,ll>> res;
  for(ll u = 1; u <= n; u++){
    vector<pair<ll,ll>> tmp;
    Dsu tmpConnections1(connections1), tmpConnections2(connections2);
    for(ll v = 1; v <= n; v++){
      if(tmpConnections1.canConnect(u,v) && tmpConnections2.canConnect(u,v)){
        tmpConnections1.unionSet(u,v);
        tmpConnections2.unionSet(u,v);
        tmp.pb({u,v});
      }
    }
    if(res.size() < tmp.size()) res = tmp;
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el.first << " " << el.second << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}