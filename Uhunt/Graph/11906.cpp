#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
ll n,m,r,c;

void dfs(ll x, ll y, vector<vector<ll>> &grid){
  grid[x][y] = 1;
  ll cnt=0;
  vector<pair<ll, ll>> dir{{x-n, y-m}, {x-m, y-n}, {x+n, y+m}, {x+m, y+n}, {x+n, y-m}, {x-n, y+m}, {x-m, y+n}, {x+m, y-n}};
  map<pair<ll, ll>, bool> vis;
  for(auto el : dir){
    if(el.first >= 0 && el.first < r && el.second >= 0 && el.second < c && grid[el.first][el.second]==0){
      dfs(el.first, el.second, grid);
    }
    if(el.first >= 0 && el.first < r && el.second >= 0 && el.second < c && (grid[el.first][el.second]==1 || grid[el.first][el.second]==2) && !vis[{el.first, el.second}]){
      cnt++;
    }
    vis[{el.first, el.second}] = true;
  }
  if(!(cnt&1)) grid[x][y] = 2;
}



void solve(){
  ll w,x,y;
  cin >> r >> c >> m >> n >> w;
  vector<vector<ll>> grid(r, vector<ll>(c, 0));
  for(ll i = 0; i < w; i++){
    cin >> x >> y;
    grid[x][y] = -1;
  }
  
  dfs(0, 0, grid);
  ll even=0,odd=0;
  for(ll i = 0; i < r; i++){
    for(ll j = 0; j < c; j++){
      // cout << grid[i][j] << " ";
      if(grid[i][j] == 1) odd++;
      if(grid[i][j] == 2) even++;
    }
    // cout << endl;
  }
  cout << even << " " << odd << endl;
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
  for(ll i = 1; i <= t; i++){
    cout << "Case " << i << ": ";
    solve();
  }
}