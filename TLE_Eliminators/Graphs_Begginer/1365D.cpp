#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
vector<int> dirI = {-1,0,1,0};
vector<int> dirJ = {0,1,0,-1};
vector<string> grid;
vector<vector<bool>> vis;

bool in_range(int i, int j){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}

void dfs(int i, int j){
  vis[i][j] = true;
  for(int k = 0; k < 4; k++){
    int i1 = i+dirI[k];
    int j1 = j+dirJ[k];
    if(in_range(i1,j1) && grid[i1][j1] != '#' && !vis[i1][j1]) dfs(i1,j1);
  }
}

void solve(){
  cin >> n >> m;
  grid.assign(n, " ");
  vis.assign(n, vector<bool>(m, false));
  for(int i = 0; i < n; i++) cin >> grid[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'B'){
        for(int k = 0; k < 4; k++){
          int i1 = i+dirI[k];
          int j1 = j+dirJ[k];
          // dbg(i1,j1, in_range(i1,j1));
          if(in_range(i1,j1) && grid[i1][j1] == '.') grid[i1][j1] = '#';
        }
      } 
    }
  }
  if(grid[n-1][m-1] != '#') dfs(n-1,m-1);
  int good=0,bad=0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'G') good++;
      if(grid[i][j] == 'B') bad++;
    }
  }
  int vis_good=0,vis_bad=0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'G' && vis[i][j]) vis_good++;
      if(grid[i][j] == 'B' && vis[i][j]) vis_bad++;
    }
  }
  if(vis_good == good && vis_bad == 0){
    cout << "Yes\n";
  } else{
    cout << "No\n";
  }
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

  int t;
  cin >> t;
  while(t--)
  solve();
}