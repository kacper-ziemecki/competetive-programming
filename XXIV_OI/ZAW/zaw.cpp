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

int n,u,v,res=1;
int mod = 1e9+7;
char c;
bool jestCykl = false;
const int maxn = 1e6+1;
vector<pair<int,int>> adj[maxn];
vector<int> pojedyncze;
int deg[maxn], ustawienie[maxn], koncowaLista[maxn];
int vis[maxn];
bool uzyte[maxn];

void dfsPojedyncze(int u){
  vis[u] = 1;
  for(auto [v,id] : adj[u]){
    if(!vis[v]){
      ustawienie[v] = id;
      dfsPojedyncze(v);
    }
  }
}
bool cycle(int u){
  vis[u] = -1;
  bool flag = false;
  for(auto [v,id] : adj[u]){
    if(vis[v] == -1){
      flag = true;
      jestCykl = true;
    }
    if(!vis[v]){
      ustawienie[u] = id;
      flag = flag | cycle(v);
    }
  }
  vis[u] = 1;
  return flag;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> c;
    if(c == 'N'){
      cin >> u >> v;
      uzyte[u] = true;
      uzyte[v] = true;
      adj[u].pb(make_pair(v,i+1));
      adj[v].pb(make_pair(u,i+1));
      deg[v]++;
      deg[u]++;
    } else{
      cin >> u;
      uzyte[u] = true;
      adj[u].pb(make_pair(u,i+1));
      ustawienie[u] = i+1;
      deg[u]++;
      pojedyncze.pb(u);
    }
  }
  for(int u = 1; u <= n; u++){
    if(!uzyte[u]){
      cout << "NIE\n";
      cout << 0 << endl;
      return;
    }
  }
  for(auto u : pojedyncze) dfsPojedyncze(u);
  for(int u = 1; u <= n; u++){
    if(deg[u] == 1 && !vis[u] && cycle(u)) res = (res << 1) % mod;
  }
  for(int u = 1; u <= n; u++){
    if(!vis[u] && cycle(u)) res = (res << 1) % mod;
  }
  if(!jestCykl){
    cout << "TAK\n";
    for(int u = 1; u <= n; u++){
      koncowaLista[ustawienie[u]] = u;
    }
    for(int i = 1; i <= n; i++){
      cout << koncowaLista[i] << endl;
    }
  } else{
    cout << "NIE\n";
    cout << res << endl;
  }
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