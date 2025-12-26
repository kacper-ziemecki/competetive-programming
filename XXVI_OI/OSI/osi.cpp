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

int n,m;
const int maxn = 1e6+1;
vector<int> adj[maxn]; // adj[u] -> numery krawędzi które zaczynają sie na "u"
vector<int> adj_res[maxn], adj_res_t[maxn];
bool vis[maxn]; // czy jakis numer krawedzi jest odwiedzony
string s(maxn, ' ');
pair<int,int> edges[maxn];
vector<int> order;

void dfs(int u){
  for(auto v : adj[u]){
    if(!vis[v]){
      s[v] = (u == edges[v].first ? '>' : '<');
      vis[v] = true;
      dfs(u == edges[v].first ? edges[v].second : edges[v].first);
    }
  }
}

void dfs1(int u){
  vis[u] = true;
  for(auto v : adj_res[u]){
    if(!vis[v]) dfs1(v);
  }
  order.pb(u);
}

void dfs2(int u){
  vis[u] = true;
  for(auto v : adj_res_t[u]){
    if(!vis[v]) dfs2(v);
  }
}
void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> edges[i].first >> edges[i].second;
    adj[edges[i].first].pb(i);
    adj[edges[i].second].pb(i);
  }
  for(int i = 0; i < m; i++){
    if(!vis[i]){
      dfs(edges[i].first);
    }
  }
  for(int i = 0; i < m; i++){
    if(s[i] == '>'){
      adj_res[edges[i].first].pb(edges[i].second);
      adj_res_t[edges[i].second].pb(edges[i].first);
    } else{
      adj_res_t[edges[i].first].pb(edges[i].second);
      adj_res[edges[i].second].pb(edges[i].first);
    }
  }
  for(int i = 1; i <= n; i++) vis[i] = false;
  for(int i = 1; i <= n; i++){
    if(!vis[i]) dfs1(i);
  }
  reverse(order.begin(), order.end());
  int cnt = 0;
  for(int i = 1; i <= n; i++) vis[i] = false;
  for(auto el : order){
    if(!vis[el]){
      dfs2(el);
      cnt++;
    }
  }
  cout << cnt << endl;
  cout << s.substr(0, m) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}