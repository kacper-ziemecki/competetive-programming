#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool inBounds(ll x, ll y, ll n, ll m){
  if(x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}

ll dfs(ll x, ll y, ll n, ll m, vector<string> &adj, char el){
  adj[x][y] = el-1;
  ll cnt=1;
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, 1, 0, -1};
  for(ll i = 0; i < 4; i++){
    ll x1 = x+dx[i], y1 = (y+dy[i]+m)%m;
    if(inBounds(x1, y1, n, m) && adj[x1][y1] == el) cnt+=dfs(x1,y1,n,m,adj, el);
  }
  return cnt;
}

void solve(ll n, ll m){
  vector<string> adj(n);
  ll res=0;
  for(auto &el : adj) cin >> el;
  ll x,y;
  cin >> x >> y;
  char el = adj[x][y];
  dfs(x,y,n,m,adj, el);
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(adj[i][j] == el) res = max(res, dfs(i,j,n,m,adj,el));
    }
  }
  cout << res << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll n,m;
  while(cin >> n >> m, !cin.eof()) solve(n,m);
}