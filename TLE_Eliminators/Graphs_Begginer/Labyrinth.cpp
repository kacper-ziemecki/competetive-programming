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
const int N = 1e3+1;
const int INF = 1e7;
int dist[N][N];
string grid[N];
bool vis[N][N];
int parent[N][N];
pair<int,int> start,ending;
vector<int> dirI = {-1,0,1,0};
vector<int> dirJ = {0,1,0,-1};

bool in_grid(int i, int j){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}


void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> grid[i];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      dist[i][j] = INF;
      if(grid[i][j] == 'A'){
        start = make_pair(i,j);
      }
      if(grid[i][j] == 'B'){
        ending = make_pair(i,j);
      }
    }
  }

  queue<pair<int,int>> q;
  vis[start.first][start.second] = true;
  dist[start.first][start.second] = 0;
  q.push(start);
  while(!q.empty()){
    pair<int,int> node = q.front(); q.pop();
    for(int k = 0; k < 4; k++){
      int i1 = node.first+dirI[k];
      int j1 = node.second+dirJ[k];
      if(!in_grid(i1,j1) || vis[i1][j1] || grid[i1][j1] == '#') continue;
      dist[i1][j1] = dist[node.first][node.second]+1;
      parent[i1][j1] = k;
      vis[i1][j1] = true;
      q.push(make_pair(i1,j1));
    }
  }
  if(dist[ending.first][ending.second] == INF){
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << dist[ending.first][ending.second] << endl;
  string s;
  while(!(ending.first == start.first && ending.second == start.second)){
    int k = parent[ending.first][ending.second];
    s += "URDL"[k];
    ending.first -= dirI[k];
    ending.second -= dirJ[k];
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}