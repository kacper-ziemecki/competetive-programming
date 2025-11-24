#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool inBounds(ll x, ll y, ll n, vector<string>& adj){
  if(x >= 0 && x < n && y >= 0 && y < adj[x].size()) return true;
  return false;
}

void dfs(ll x, ll y, ll n, vector<string>& adj, char el){
  adj[x][y] = el;
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, -1, 0, 1};
  for(ll i = 0; i < 4; i++){
    ll x1=x+dx[i], y1=y+dy[i];
    if(inBounds(x1,y1,n,adj) && adj[x1][y1] == ' ') dfs(x1,y1,n,adj,el);
  }
}

void solve(){
  vector<string> adj;
  string s;
  ll n=0,m=0;
  while(getline(cin, s), s[0] != '_'){
    adj.push_back(s);
    m = max(m, (ll)s.size());
    n++;
    if(n > 32) return;
  }
  char wall;
  bool haveWall=false;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < adj[i].size(); j++){
      if(adj[i][j] != ' ' && (ll)adj[i][j] != 13){
        wall = adj[i][j];
        haveWall = true;
        break;
      }
    }
    if(haveWall) break;
  }
  vector<tuple<ll, ll, char>> cords;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < adj[i].size(); j++){
      if(adj[i][j] != ' ' && adj[i][j] != wall && (ll)adj[i][j] != 13){
        cords.push_back(make_tuple(i, j, adj[i][j]));
        adj[i][j] = ' ';
      }
    }
  }
  for(auto el : cords){
    dfs(get<0>(el), get<1>(el),n,adj,get<2>(el));
  }
  for(auto el : adj) cout << el << endl;
  cout << s << endl;
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

  while(!cin.eof()){
    solve();
  }
}