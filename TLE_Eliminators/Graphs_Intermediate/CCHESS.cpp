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

ll a,b,c,d;
const ll N = 8;
ll dist[N][N];
vector<ll> movesI = {-2,-2,-1,1,2,2,-1,1};
vector<ll> movesJ = {-1,1,2,2,1,-1,-2,-2};

bool in_bounds(ll i, ll j){
  if(i < 0 || j < 0 || i >= N || j >= N) return false;
  return true;
}

void solve(){
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < N; j++) dist[i][j] = LLONG_MAX;
  }
  priority_queue<vector<ll>, vector<vector<ll>>, greater<>> pq;
  dist[a][b] = 0; 
  pq.emplace(vector<ll>{0, a, b});
  while(!pq.empty()){
    ll d = pq.top()[0];
    ll i = pq.top()[1];
    ll j = pq.top()[2];
    pq.pop();
    if(d != dist[i][j]) continue;
    for(ll k = 0; k < 8; k++){
      ll i1 = i + movesI[k];
      ll j1 = j + movesJ[k];
      if(!in_bounds(i1,j1)) continue;
      if(dist[i1][j1] > d+(i*i1+j*j1)){
        dist[i1][j1] = d+(i*i1+j*j1);
        pq.emplace(vector<ll>{dist[i1][j1], i1, j1});
      }
    }
  } 
  cout << dist[c][d] << endl;
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

  while(cin >> a >> b >> c >> d){
    solve();
  }
}