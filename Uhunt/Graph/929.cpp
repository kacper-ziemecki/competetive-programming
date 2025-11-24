#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool canMove(ll x,ll y,ll n,ll m){
  if(x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}

void solve(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> mt(n, vector<ll>(m)), dist(n, vector<ll>(m, LLONG_MAX));
  priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      cin >> mt[i][j];
    }
  }
  dist[0][0] = mt[0][0];
  pq.emplace(dist[0][0], 0, 0);
  while(!pq.empty()){
    auto [w, x, y] = pq.top(); pq.pop();
    vector<ll> dx{-1, 0, 1, 0};
    vector<ll> dy{0, -1, 0, 1};
    for(ll i = 0; i < 4; i++){
      ll x1=x+dx[i],y1=y+dy[i];
      if(canMove(x1,y1,n,m) && dist[x1][y1] > w+mt[x1][y1]){
        dist[x1][y1] = w+mt[x1][y1];
        pq.emplace(dist[x1][y1],x1,y1);
      }
    }
  }
  cout << dist[n-1][m-1] << endl;
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
  while(t--) solve();
}