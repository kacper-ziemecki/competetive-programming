#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n;
const ll maxN = 2e5+1;
vector<ll> adj[maxN];
ll dp[maxN][2];

ll dfs(ll u, ll choice, ll p){
  // dbg(u,choice,p);
  if(adj[u].size() == 1 && adj[u][0] == p) return 0;
  if(dp[u][choice] != -1) return dp[u][choice];
  dp[u][choice] = 0;
  bool flag = false;
  for(auto v : adj[u]){
    if(v == p) continue;
    ll chose = dfs(v,1,u);
    ll notChose = dfs(v,0,u);
    if(notChose >= chose) flag = true;
    dp[u][choice] += max(chose, notChose);
  }
  dp[u][choice] += (flag && choice);
  return dp[u][choice];
}

void solve()
{
  cin >> n;
  for(ll i = 0; i <= n; i++){
    dp[i][0] = -1; dp[i][1] = -1;
  }
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }  
  cout << max(dfs(1, 0, -1), dfs(1, 1, -1)) << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}