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

vector<ll> p,_size;

ll find_set(ll a){ return (p[a] == a ? a : p[a] = find_set(p[a])); }

void union_set(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a, b);
  p[b] = a;
  _size[a] += _size[b];
}


bool check(vector<vector<ll>>& adj, ll m, ll n, ll s){
  vector<ll> deg(n+1);

  p.assign(n+1, 0); _size.assign(n+1, 1);
  for(ll i = 1; i <= n; i++) p[i] = i;
  for(ll u = 1; u <= n; u++) deg[u] = adj[u].size();
  queue<ll> q;
  for(ll u = 1; u <= n; u++) if(deg[u] == 1) q.emplace(u); //leaf node
  while(!q.empty()){
    ll u = q.front(); q.pop();
    for(auto v : adj[u]){
      if(--deg[v] == 1) q.emplace(v); //leaf node

      if(deg[v] >= 1 && _size[find_set(u)] < m) union_set(u, v);
    }
  }
  set<ll> st;
  for(ll u = 1; u <= n; u++){
    // dbg(u, _size[find_set(u)], m);
    if(_size[find_set(u)] >= m) st.emplace(find_set(u));
  }
  return st.size() >= s;
} 

void solve()
{
  ll n,s;
  cin >> n >> s;
  cout <<n<<"."<<s<<endl;
  vector<vector<ll>> adj(n+1);
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  ll l = 1, r = n;
  while(l < r){
    ll m = (l+r+1)/2;
    if(check(adj, m, n, s)) l = m;
    else r = m-1;
  }
  cout << l << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  solve();
}