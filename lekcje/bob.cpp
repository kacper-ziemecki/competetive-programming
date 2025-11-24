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

map<ll, ll> p, _size;

ll find_set(ll a){
  return (p[a] == a ? a : p[a] = find_set(p[a]));
}

void union_set(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
}

void solve()
{
  ll n,m,u,v;
  cin >> n >> m;
  map<ll,vector<ll>> adj;
  set<ll> vertices;
  map<ll, ll> in_deg, out_deg;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    vertices.emplace(u); vertices.emplace(v);
    adj[u].pb(v);
    out_deg[u]++;
    in_deg[v]++;
  }
  for(auto el : vertices){ p[el] = el; _size[el] = 1; }

  for(auto [u, children]: adj){
    for(auto v : children){
      union_set(u,v);
    }
  }

  map<ll, ll> mp;
  for(auto el : vertices){
    if(_size[find_set(el)] == 1) continue;
    mp[find_set(el)] += max(0ll, in_deg[el]-out_deg[el]);
  }
  bool flag = (mp.size()==1);
  for(auto el : mp){ flag &= (el.second==0); }
  ll res=0;
  for(auto el : mp){ res += (el.second ? el.second : 1); }
  if(flag){ cout << 0 << endl; return; }
  cout << res << endl; 
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}