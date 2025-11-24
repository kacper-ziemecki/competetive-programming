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

void dfs(ll x, ll y, ll n, ll m, vector<string> &adj){
  adj[x][y] = '#';
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, 1, 0, -1};
  for(ll i = 0; i < 4; i++){
    ll x1 = x+dx[i], y1 = y+dy[i];
    if(inBounds(x1, y1, n, m) && adj[x1][y1] == ' ') dfs(x1, y1, n, m, adj);
  }
}

void solve(){
  vector<string> adj;
  string s;
  ll n=0,m=0;
  while(getline(cin >> ws, s), s[0] != '_'){
    adj.push_back(s);
    n++;
  }
  if(n) m = adj[0].size();
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(adj[i][j] == '*'){ dfs(i, j, n, m, adj); break; }
    }
  }
  for(auto el : adj) cout << el << endl;
  cout << "_____\n";

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

  ll t;
  cin >> t;
  while(t--) solve();
}