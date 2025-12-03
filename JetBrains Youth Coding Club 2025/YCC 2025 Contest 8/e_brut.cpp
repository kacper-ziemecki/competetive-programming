#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m,k,tim=0;
const int maxn = 1e5+1;
int cords[maxn][2];
map<pair<pair<int,int>,pair<int,int>>, int> dist;

void change_dir(pair<int,int> &_od, pair<int,int> &dir){
  if(_od.first == 0 || _od.first == n){
    dir.first = -dir.first;
  }
  if(_od.second == 0 || _od.second == m){
    dir.second = -dir.second;
  }
}

pair<int,int> go_to(pair<int,int> &_od, pair<int,int> &dir){
  pair<int,int> _do;
  int distI,distJ;
  if(dir.first < 0) distI = _od.first;
  else distI = n-_od.first;
  if(dir.second < 0) distJ = _od.second;
  else distJ = m-_od.second;
  _do = {_od.first + min(distI, distJ) * dir.first, _od.second + min(distI,distJ) * dir.second};
  change_dir(_do,dir);
  return _do;
}
int odleglosc(pair<int,int> a, pair<int,int> b){
  return abs(a.first - b.first); 
}

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++){
    cin >> cords[i][0] >> cords[i][1];
  }
  pair<int,int> _od = {0,0};
  pair<int,int> dir = {1,1};
  pair<int,int> _do = go_to(_od,dir);
  int distance = 0;
  while(dist.count({_od,_do}) == 0){
    // dbg(_od.first,_od.second,_do.first,_do.second);
    // dbg(dir.first,dir.second);
    dist[{_od,_do}] = distance;
    // dbg(distance);
    distance += abs(_od.first-_do.first);
    _od = _do;
    _do = go_to(_od,dir);
  }
  for(int i = 0; i < k; i++){
    int res = INT_MAX;
    pair<int,int> cur = {cords[i][0], cords[i][1]};
    pair<int,int> dir1 = {1, -1}, dir2 = {-1, 1};
    pair<pair<int,int>,pair<int,int>> jeden = {go_to(cur, dir1), go_to(cur, dir2)};
    if(dist.count(jeden)) res = min(res, dist[jeden]+odleglosc(jeden.first,cur));
    pair<pair<int,int>,pair<int,int>> dwa = {jeden.second,jeden.first};
    if(dist.count(dwa)) res = min(res, dist[dwa]+odleglosc(dwa.first,cur));
    dir1 = {1, 1}; dir2 = {-1, -1};
    pair<pair<int,int>,pair<int,int>> trzy = {go_to(cur,dir1), go_to(cur,dir2)};
    if(dist.count(trzy)) res = min(res, dist[trzy]+odleglosc(trzy.first,cur));
    pair<pair<int,int>,pair<int,int>> cztery = {trzy.second, trzy.first};
    if(dist.count(cztery)) res = min(res, dist[cztery]+odleglosc(cztery.first,cur));
    
    if(res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
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