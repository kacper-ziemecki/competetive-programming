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
const int N = 51;
string grid[N];
int vis[N][N];
vector<int> dirI = {-1,0,1,0};
vector<int> dirJ = {0,1,0,-1};

bool in_grid(int i, int j){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}

bool cycle(int i, int j, int prevI, int prevJ, char c){
  vis[i][j] = 1;
  for(int k = 0; k < 4; k++){
    int i1 = i+dirI[k];
    int j1 = j+dirJ[k];
    if(!in_grid(i1,j1) || (i1==prevI && j1==prevJ) || c != grid[i1][j1]) continue;
    if(vis[i1][j1] == 1){
      return true;
    }
    if(vis[i1][j1] == 0 && cycle(i1,j1,i,j,c)) return true;
  }
  vis[i][j] = -1;
  return false;
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> grid[i]; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j] == 0 && cycle(i,j,i,j,grid[i][j])){
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
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

  solve();
}