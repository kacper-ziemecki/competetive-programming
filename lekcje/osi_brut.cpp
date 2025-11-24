#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m,u,v,res=INT_MAX, ans;
const int maxN = 1e6+1, maxM = 20, maxMask=1<<20;
vector<int> adj[maxN], adj_t[maxN], order;
pair<int,int> edges[maxM];
bool vis[maxN];
unsigned int bit;

void reset(){
  order.clear();
  for(int i = 0; i < maxN; i++){
    adj[i].clear();
    adj_t[i].clear();
  }
}
void reset_vis(){
  for(int i = 0; i < maxN; i++) vis[i] = false;
}

void dfs1(int u){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) dfs1(v);
  }
  order.pb(u);
}

void dfs2(int u){
  vis[u] = true;
  for(auto v : adj_t[u]){
    if(!vis[v]) dfs2(v);
  }
}

int helper(){
  reset();
  for(int i = 0; i < m; i++){
    auto [u,v] = edges[i];
    if(bit&(1<<i)){ //u->v
      adj[u].pb(v);
      adj_t[v].pb(u);
    } else{ //v->u
      adj[v].pb(u);
      adj_t[u].pb(v);
    }
  }
  reset_vis();
  for(int i = 1; i <= n; i++){
    if(!vis[i]) dfs1(i);
  }
  reverse(order.begin(), order.end());

  int curRes = 0;
  reset_vis();
  for(auto u : order){
    if(!vis[u]){
      curRes++;
      dfs2(u);
    }
  }
  return curRes;
}

string show(int x){
  string answer;
  for(int i = 0; i < m; i++){
    answer += (x&(1<<i) ? '>' : '<');
  }
  return answer;
}

void solve()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    edges[i] = {u,v};
  }
  for(int i = 0; i < (1<<min(n-1, 20)); i++){
    int curRes = helper();
    if(curRes < res){
      res = curRes;
      ans = i;
    }
    bit++;
  }
  cout << res << endl;
  cout << show(ans) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}