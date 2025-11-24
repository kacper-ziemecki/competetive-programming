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

ll dfs(ll x, ll y, ll n, ll m, vector<string> &adj){
  adj[x][y] = '0';
  ll cnt = 1;
  vector<ll> dx{-1, 0, 1, 1, 1, 0, -1, -1};
  vector<ll> dy{-1, -1, -1, 0, 1, 1, 1, 0};
  for(ll i = 0; i < 8; i++){
    if(inBounds(x+dx[i], y+dy[i], n, m) && adj[x+dx[i]][y+dy[i]] == '1') cnt += dfs(x+dx[i], y+dy[i], n, m, adj);
  }
  return cnt;
}

void solve(){
  vector<string> adj;
  string s;
  ll n = 0;
  for(ll i = 0;; i++){
    getline(cin, s);
    // dbg(s);
    // dbg(s.size());
    // dbg(s[0]);
    // dbg(!(s[0] == '0' || s[0] == '1'));
    if(!(s[0] == '0' || s[0] == '1')) break;
    adj.push_back(s);
    n++;
    if(cin.eof()) break;
  }
  if(n == 0){ cout << 0 << endl; cin.ignore(); cin.ignore();return;}
  ll m = adj[0].size();
  // cout << "lista:\n";
  // for(auto el : adj) cout << el << endl;

  ll res = 0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(adj[i][j] == '1') res = max(res, dfs(i, j, n, m, adj));
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
  
  ll t;
  cin >> t;
  cin.ignore();
  cin.ignore();
  cin.ignore();
  cin.ignore();
  ll i = 0;
  while(t--){
    if(i++ != 0) cout << endl;
    solve();
  }
}