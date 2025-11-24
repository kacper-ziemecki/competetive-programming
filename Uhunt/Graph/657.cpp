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
ll dfs1(ll x, ll y, ll n, ll m, vector<string> &adj);

void dfs2(ll x, ll y, ll n, ll m, vector<string> &adj){
  adj[x][y] = '*';
  // cout << "dfs2\n";
  // for(auto el : adj) cout << el << endl;
  // cout << "---------\n";
  vector<ll> dx{1, -1, 0, 0};
  vector<ll> dy{0, 0, 1, -1};
  for(ll i = 0; i < 4; i++){
    // dbg(x+dx[i], y+dy[i]);
    if(inBounds(x+dx[i], y+dy[i], n, m) && adj[x+dx[i]][y+dy[i]] == 'X') dfs2(x+dx[i], y+dy[i], n, m, adj);
  } 
}

ll dfs1(ll x, ll y, ll n, ll m, vector<string> &adj){
  ll cnt = 0;
  if(adj[x][y] == 'X'){
    dfs2(x,y,n,m,adj);
    cnt++;
  }
  adj[x][y] = '.';
  // cout << "dfs1\n";
  // for(auto el : adj) cout << el << endl;
  // cout << "---------\n";
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, 1, 0, -1};
  for(ll i = 0; i < 4; i++){
    if(inBounds(x+dx[i], y+dy[i], n, m) && adj[x+dx[i]][y+dy[i]] != '.') cnt += dfs1(x+dx[i], y+dy[i], n, m, adj);
  }
  return cnt;

}

void solve(ll m, ll n){
  vector<string> adj(n);
  vector<ll> res;
  for(auto &el : adj) cin >> el;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(adj[i][j] != '.') res.push_back(dfs1(i, j, n, m, adj));
    }
  }
  sort(res.begin(), res.end());
  for(ll i = 0; i < res.size(); i++){
    if(i != 0) cout << " ";
    cout << res[i];
  }
  cout << endl;
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
  ll t=1;
  while(cin >> n >> m, n != 0 || m != 0){
    cout << "Throw " << t++ << endl;
    solve(n,m);
    cout << endl;
  }
}