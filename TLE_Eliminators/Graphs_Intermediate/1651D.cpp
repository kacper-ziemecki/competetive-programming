#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n; 
int x,y,x1,_y1,d;
set<pair<int,int>> cords,sources,vis;
map<pair<int,int>, int> dist, order;
map<pair<int,int>, pair<int,int>> parent;
vector<int> dirY = {1,0,-1,0};
vector<int> dirX = {0,1,0,-1};
vector<pair<int,int>> res;
// priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
queue<pair<int,int>> q;
void solve(){
  cin >> n;
  res.resize(n);
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    cords.emplace(make_pair(x,y));
    order[make_pair(x,y)] = i;
  }
  for(auto cord : cords){
    for(int k = 0; k < 4; k++){
      x = cord.first+dirX[k];
      y = cord.second+dirY[k];
      if(!cords.count(make_pair(x,y))){
        sources.emplace(make_pair(x,y));
      }
    }
  }
  for(auto cord : sources){
    q.emplace(cord);
    vis.emplace(cord);
    dist[cord] = 0;
    parent[cord] = cord;
    // pq.emplace(vector<int>{0,cord.first,cord.second});
  }
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    q.pop();
    // x = pq.top().first;
    // y = pq.top().second;
    for(int k = 0; k < 4; k++){
      x1 = x+dirX[k];
      _y1 = y+dirY[k];
      if(cords.count(make_pair(x1,_y1)) && !vis.count(make_pair(x1,_y1))){
        dist[make_pair(x1,_y1)] = dist[make_pair(x,y)]+1;
        q.emplace(make_pair(x1,_y1));
        vis.emplace(make_pair(x1,_y1));
        parent[make_pair(x1,_y1)] = parent[make_pair(x,y)];
      }
    }
  }
  for(auto cord : cords){
    res[order[cord]] = parent[cord];
    // dbg(cord.first,cord.second);
    // dbg(parent[cord].first, parent[cord].second);
    // cout << dist[cord] << endl;
  }
  for(auto result : res){
    cout << result.first << ' ' << result.second << endl;
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

  solve();
}