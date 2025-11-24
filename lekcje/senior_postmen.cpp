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

void dfs(ll u, vector<vector<ll>>& adj, vector<unordered_map<ll,bool>>& vis, vector<ll>& euler){
  for(auto v : adj[u]){
    if(!vis[u][v]){
      vis[u][v]=true; vis[v][u]=true;
      dfs(v,adj,vis,euler);
    }
  }
  euler.pb(u);
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> adj(n+1);
  vector<ll> euler;
  stack<ll> st;
  unordered_map<ll,ll> cnt;
  vector<unordered_map<ll,bool>> vis(n+1);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,adj,vis,euler);
  // for(auto el : euler) cout << el << " ";
  // cout << endl << endl;
  for(auto el : euler){
    if(cnt[el] > 0){
      while(st.top() != el){
        cnt[st.top()]--;
        cout << st.top() << " ";
        st.pop();
      }
      cout << st.top() << endl;
    } else{
      st.push(el);
      cnt[el]++;
    }
  }
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  solve();
}