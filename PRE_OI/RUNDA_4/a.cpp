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

int n,m,q;
const int N = 1e5+1;
const int L = ceil(log2(N))+1;
ll up[N][L], cost[N][L];
ll lista[N];
ll x;
ll t,y,a,b,r,z;

void solve(){
  cin >> n >> m >> q;
  for(int i = 0; i < n; i++) cin >> lista[i];
  up[n-1][0] = n-1;
  for(int i = n-1; i >= 0; i--){
    up[i][0] = (i == n-1 ? n-1 : i+1);
    cost[i][0] = (i == n-1 ? 0 : min(abs(lista[i+1]-lista[i]), lista[i]+1+(m-1-lista[i+1])));
    for(int j = 1; j < L; j++){
      up[i][j] = up[up[i][j-1]][j-1];
      cost[i][j] = cost[i][j-1] + cost[up[i][j-1]][j-1];
    }
  }
  for(int i = 0; i < q; i++){
    cin >> t;
    if(t==1){
      cin >> y;
    } else{
      cin >> y >> z;
      a = (x+y)%n;
      b = (x+z)%n;
      int dist = b-a;
      x = 0;
      for(int j = L-1; j >= 0; j--){
        if(dist&(1<<j)){
          x += cost[a][j];
          a = up[a][j];
        }
      }
      cout << x << endl;
    }
  }
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