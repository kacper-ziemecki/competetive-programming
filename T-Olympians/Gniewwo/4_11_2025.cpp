#include <bits/stdc++.h>
using namespace std;


int n;

struct point{
  int x,y;
}

vector<point> points;
vector<bool> vis;
vector<pair<point,point>> wynik;
int cnt=0;

bool fr(){
  if(cnt == 2*n){
    
  }
  for(int i = 0; i < 2*n; i++){
    for(int j = 0; j < 2*n; j++){
      if(i == j || vis[i] || vis[j]) continue;
      vis[i] = vis[j] = true;
      wynik.push_back({points[i], points[j]});
      cnt += 2;
      if(fr()){
        return true;
      }
      cnt -= 2;
      vis[i] = vis[j] = false;
      wynik.pop_back();
    }
  }
  return false;
}

 
int main()
{

  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);

  cin >> n;
  points.resize(2*n);
  vis.assign(2*n, false);
  for(int i = 0; i < 2*n; i++){
    cin >> points[i].x >> points[i].y;
  }
  fr();


} 