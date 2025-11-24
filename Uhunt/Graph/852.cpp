#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool inBounds(ll x, ll y){
  if(x >= 0 && x < 9 && y >= 0 && y < 9) return true;
  return false;
}

pair<bool, bool> dfs(ll x, ll y, vector<string> &adj, char el1 = '.', char el2 = '+'){
  adj[x][y] = el2;
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, 1, 0, -1};
  pair<bool, bool> res{false,false},tmp;
  for(ll i = 0; i < 4; i++){
    ll x1 = x+dx[i], y1 = y+dy[i];
    if(inBounds(x1,y1) && adj[x1][y1] == el1){
      tmp = dfs(x1,y1,adj,el1,el2);
      res = {res.first | tmp.first, res.second | tmp.second};
    }
    else if(inBounds(x1,y1) && adj[x1][y1] == 'O') res.second = true;
    else if(inBounds(x1,y1) && adj[x1][y1] == 'X') res.first = true;
  }
  return res;
}

void solve(){
  vector<string> adj(9);
  for(auto &el : adj) cin >> el;
  for(ll i = 0; i < 9; i++){
    for(ll j = 0; j < 9; j++){
      if(adj[i][j] == '.'){
        pair<bool, bool> res = dfs(i,j,adj);
        if(res.first && !res.second) dfs(i,j,adj,'+','X');
        else if(!res.first && res.second) dfs(i,j,adj,'+','O');
      }
    }
  }
  ll a=0,b=0;
  for(ll i = 0; i < 9; i++){
    for(ll j = 0; j < 9; j++){
      if(adj[i][j] == 'X') a++;
      else if(adj[i][j] == 'O') b++;
    }
  }
  cout << "Black " << a << " White " << b << endl;
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