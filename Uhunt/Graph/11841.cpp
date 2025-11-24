#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

map<vector<ll>, vector<ll>> p;
map<vector<ll>, ll> _size;
map<vector<ll>, vector<bool>> edges;

void joinEdges(vector<ll> a, vector<ll> b){
  for(ll i = 0; i < 3; i++){
    edges[a][i] = edges[a][i] || edges[b][i];
  }
}
bool equals(vector<ll> a, vector<ll> b){
  if(a.size() != b.size()) return false;
  for(ll i = 0; i < a.size(); i++) if(a[i] != b[i]) return false;
  return true;
}
vector<ll> findSet(vector<ll> a){
  return (a == p[a] ? a : p[a] = findSet(p[a]));
}
void unionSet(vector<ll> a, vector<ll> b){
  a = findSet(a);
  b = findSet(b);
  if(equals(a, b)) return;
  if(_size[a] < _size[b]) swap(a, b);
  p[b] = a;
  _size[a] += _size[b];
  joinEdges(a, b);
}
void createSet(vector<ll> &a){
  p[a] = a;
  _size[a] = 1;
  edges[a] = {false, false, false};
  if(a[0] == 0) edges[a][0] = true;
  if(a[1] == 0) edges[a][1] = true;
  if(a[2] == 0) edges[a][2] = true;
}
bool canConnect(vector<ll> a, vector<ll> b){
  if(a[0]-1 == b[0] && a[1]+1 == b[1] && a[2] == b[2]) return true;
  if(a[0]-1 == b[0] && a[1] == b[1] && a[2]+1 == b[2]) return true;
  if(a[0] == b[0] && a[1]-1 == b[1] && a[2]+1 == b[2]) return true;
  if(a[0]+1 == b[0] && a[1]-1 == b[1] && a[2] == b[2]) return true;
  if(a[0]+1 == b[0] && a[1] == b[1] && a[2]-1 == b[2]) return true;
  if(a[0] == b[0] && a[1]+1 == b[1] && a[2]-1 == b[2]) return true;
  return false;
}

void solve(ll n, ll m){
  p.clear();
  _size.clear();
  edges.clear();
  vector<vector<ll>> list(m, vector<ll>(3));
  for(ll i = 0; i < m; i++){
    for(ll j = 0; j < 3; j++){
      cin >> list[i][j];
    }
  }
  for(auto el : list) createSet(el);

  // for(auto el : edges){
  //   for(auto sub : el.first) cout << sub << " ";
  //   cout << "-> ";
  //   for(auto sub : el.second) cout << sub << " ";
  //   cout << endl;
  // }

  for(ll i = 0; i < m; i++){
    for(ll j = 0; j < m; j++){
      if(canConnect(list[i], list[j])) unionSet(list[i], list[j]);
    }
  }

  for(auto el : list){
    vector<bool> tmp = edges[findSet(el)];
    if(tmp[0] && tmp[1] && tmp[2]){
      cout << "Benny\n";
      return;
    }
  }
  cout << "Willy\n";
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
  
  ll n,m;
  while(cin >> n >> m, n != 0 || m != 0) solve(n, m);
}