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

struct Edge {
  ll to, id;
};

void dfs(ll u, vector<vector<Edge>>& adj, vector<bool>& vis_edge, vector<bool>& vis_vertex, vector<ll>& euler){
  vis_vertex[u] = true;
  for(Edge v : adj[u]){
    if(!vis_edge[v.id]){
      vis_edge[v.id] = true;
      dfs(v.to,adj,vis_edge,vis_vertex,euler);
    }
  }
  euler.pb(u);
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n+1);
  vector<vector<ll>> ans;
  vector<bool> vis_edge(m);
  vector<bool> vis_vertex(n+1, false);
  vector<ll> deg(n+1),euler;
  ll u,v,a,b;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> a >> b;
    if(a==b) continue;
    adj[u].pb({v, i}); adj[v].pb({u,i});
    deg[u]++; deg[v]++;
  }
  for(ll i = 1; i <= n; i++){ if(deg[i]&1){ cout << "NIE\n"; return; } }

  for(ll i = 1; i <= n; i++){
    if(!vis_vertex[i]){
      euler.clear();
      dfs(i,adj,vis_edge,vis_vertex,euler);
      stack<ll> st;
      unordered_set<ll> check;
      vector<ll> res;
      for(ll i = 0; i < euler.size(); i++){
        if(check.count(euler[i])) res.pb(euler[i]);
        while(check.count(euler[i])){
          res.pb(st.top());
          check.erase(st.top()); st.pop();
        }
        if(!res.empty()){
          ans.pb(res);
          res.clear(); 
        }
        st.emplace(euler[i]); check.emplace(euler[i]);
      }
    }
  }
  cout << ans.size() << endl;
  for(auto sub : ans){
    cout << sub.size()-1;
    for(auto el : sub) cout << " " << el;
    cout << endl;
  }
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  solve();
}