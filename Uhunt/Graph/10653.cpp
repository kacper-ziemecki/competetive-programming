#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool canMove(ll y, ll x, ll n, ll m){
  if(y >= 0 && y < n && x >= 0 && x < m) return true;
  return false;
}

void solve(ll n,ll m){
  vector<vector<bool>> am(n, vector<bool>(m,true));
  vector<vector<ll>> dist(n, vector<ll>(m));
  ll r;
  cin >> r;
  ll idx1,idx2,k;
  for(ll i = 0; i < r; i++){
    cin >> idx1 >> k;
    for(ll j = 0; j < k; j++){
      cin >> idx2;
      am[idx1][idx2]=false;
    }
  }
  ll sx,sy,dx,dy;
  cin >> sy >> sx >> dy >> dx;
  queue<pair<ll,ll>> q;
  q.push({sy,sx});
  am[sy][sx] = false;
  dist[sy][sx] = 0;
  while(!q.empty()){
    pair<ll,ll> p = q.front(); q.pop();
    vector<pair<ll,ll>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for(auto d: dir){
      ll cy = p.first+d.first, cx = p.second+d.second;
      if(canMove(cy,cx,n,m) && am[cy][cx]){
        am[cy][cx]=false;
        dist[cy][cx] = dist[p.first][p.second]+1;
        q.push({cy, cx});
      }
    }
  }
  cout << dist[dy][dx] << endl;
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
  while(cin>>n>>m,n!=0||m!=0) solve(n,m);
}