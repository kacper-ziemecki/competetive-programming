#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool inBounds(ll x, ll y, ll n){
  if(x >= 0 && x < n && y >= 0 && y < n) return true;
  return false;
}

void dfs(ll x, ll y, ll n, vector<vector<ll>> &adj, char el){
  adj[x][y] = -1;
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, 1, 0, -1};
  for(ll i = 0; i < 4; i++){
    ll x1 = x+dx[i], y1 = y+dy[i];
    if(inBounds(x1, y1, n) && adj[x1][y1] == el) dfs(x1,y1,n,adj,el);
  }
}

void solve(ll n){
  vector<vector<ll>> adj(n, vector<ll>(n, 0));
  string s;
  ll x,y;
  for(ll i = 1; i < n; i++){
    getline(cin >> ws, s);
    stringstream stream;
    stream << s;
    while(!stream.eof()){
      stream >> x >> y;
      adj[x-1][y-1] = i;
    }
  }
  // for(ll i = 0; i < n; i++){
  //   for(ll j = 0; j < n; j++) cout << adj[i][j] << " ";
  //   cout << endl;
  // }
  // cout << "-----\n";
  ll cnt=0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(adj[i][j] != -1){
        cnt++;
        dfs(i,j,n,adj,adj[i][j]);
      }
    }
  }
  if(cnt == n) cout << "good\n";
  else cout << "wrong\n";
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

  ll n;
  while(cin >> n, n != 0){
    solve(n);
  }
}