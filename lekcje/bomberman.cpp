#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const int maxN = 1001;
int n;
string grid[maxN];
int distK[maxN][maxN], distP[maxN][maxN];
pair<int,int> vertical[maxN][maxN], horizontal[maxN][maxN]; // dist to P, dist to K

bool vis[maxN][maxN];

void resetVis(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) vis[i][j] = false;
  }
}

void resetDist(bool dist_to_K){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!dist_to_K) distP[i][j] = -1;
      else distK[i][j] = -1;
    }
  }
}

bool inBounds(int i, int j){
  return (i >= 0 && j >= 0 && i < n && j < n);
}

void distances(int i, int j, bool dist_to_K){
  resetVis();
  resetDist(dist_to_K);
  queue<pair<int, int>> q;
  q.push({i,j});
  vis[i][j] = true;
  if(dist_to_K) distK[i][j] = 0;
  else distP[i][j] = 0;

  vector<int> dirX = {1,0,-1,0};
  vector<int> dirY = {0,1,0,-1};
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int k = 0; k < 4; k++){
      int i1 = i+dirY[k];
      int j1 = j+dirX[k];
      if(inBounds(i1,j1) && !vis[i1][j1] && grid[i1][j1] != '#' && grid[i1][j1] != 'X'){
        vis[i1][j1] = true;
        q.push({i1,j1});
        if(dist_to_K) distK[i1][j1] = distK[i][j]+1;
        else distP[i1][j1] = distP[i][j]+1;
      }
    }
  }
}

// void print(int d[maxN][maxN]){
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < n; j++){
//       cout << d[i][j] << ' ';
//     }
//     cout << endl;
//   }
//   cout << endl;
// }
void computeVerticalP(int begin, int end, int col){
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
  
  //idziemy z gory na dul
  for(int i = begin; i <= end; i++){ // srodek
    if(distP[i][col] != -1) pq.push({i+distP[i][col], {i, col}}); // srodek
    if(col-1 >= 0 && distP[i][col-1] != -1) pq.push({i+1+distP[i][col-1], {i,col-1}}); // lewo
    if(col+1 < n && distP[i][col+1] != -1) pq.push({i+1+distP[i][col+1], {i,col+1}}); // prawo
  }
  if(end+1 < n && distP[end+1][col] != -1) pq.push({end+1+dist[end+1][col], {end+1, col}});

  for(int i = begin; i <= end; i++){
    pair<int, pair<int,int>> cur = pq.top();
    while(cur.second.first < i){
      pq.pop();
      cur = pq.top();
    }
    vertical[i][col].first = cur.first-i;
  }
  // z dolu do gory
  for(int i = end; i >= begin; i--){ // srodek
    if(distP[i][col] != -1) pq.push({end-i+distP[i][col], {i, col}}); // srodek
    if(col-1 >= 0 && distP[i][col-1] != -1) pq.push({end-i+1+distP[i][col-1], {i,col-1}}); // lewo
    if(col+1 < n && distP[i][col+1] != -1) pq.push({end-i+1+distP[i][col+1], {i,col+1}}); // prawo
  }
  if(begin-1 >= 0 && distP[begin-1][col] != -1) pq.push({end-begin+1+dist[begin-1][col], {begin-1, col}});

  for(int i = end; i >= begin; i--){
    pair<int, pair<int,int>> cur = pq.top();
    while(cur.second.first > i){
      pq.pop();
      cur = pq.top();
    }
    vertical[i][col].first = min(vertical[i][col], cur.first-(end - i));
  }
}

void computeVerticalK(int begin, int end, int col){
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
  
  for(int i = begin; i <= end; i++){ // lewa i prawa strona jezeli jest vertical

  }
  for(int i = max(0, begin-1); i <= min(n-1, end+1); i++){ // srodek
    if(toP && distP[]){

    }
    if(vertical) pq.push()
  }
}

void solve()
{
	cin >> n;
  for(int i = 0; i < n; i++) cin >> grid[i];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == 'K'){
        distances(i,j, true);
      } else if(grid[i][j] == 'P'){
        distances(i,j, false);
      }
    }
  }
  
  for(int i = 0; i < n; i++){
    int begin = -1;
    for(int j = 0; j < n; j++){
      if(begin == -1 && grid[j][i] == '.'){ //poczotek
        begin = j;
      }
      if(begin != -1 && grid[j][i] == 'X'){ //koniec
        computeVerticalP(begin, j-1, i); // odleglosc od poczotku
        computeVerticalK(begin, j-1, i); // odleglosc od konca
        begin = -1;
      }
    }
  }
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}