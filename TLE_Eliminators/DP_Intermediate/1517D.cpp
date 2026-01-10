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

int n,m,k;
const int maxn = 501, maxk = 20;
int dp[maxn][maxn][maxk];
int dist_right[maxn][maxn], dist_down[maxn][maxn];

void solve(){
  cin >> n >> m >> k;
  if(k&1){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cout << -1 << ' ';
      }
      cout << endl;
    }
    return;
  }
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < maxn; j++){
      for(int x = 0; x < maxk; x++){
        dp[i][j][x] = INT_MAX;
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m-1; j++){
      cin >> dist_right[i][j];
    }
  }
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < m; j++){
      cin >> dist_down[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int gora = (i-1 < 0 ? INT_MAX : 2*dist_down[i-1][j]);
      int prawo = (j >= m-1 ? INT_MAX : 2*dist_right[i][j]);
      int dul = (i >= n-1 ? INT_MAX : 2*dist_down[i][j]);
      int lewo = (j-1 < 0 ? INT_MAX : 2*dist_right[i][j-1]);
      dp[i][j][2] = min({gora,prawo,dul,lewo});
    }
  }
  for(int x = 4; x <= k; x+=2){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        int gora = (i-1 < 0 ? INT_MAX : 2*dist_down[i-1][j] + dp[i-1][j][x-2]);
        int prawo = (j >= m-1 ? INT_MAX : 2*dist_right[i][j] + dp[i][j+1][x-2]);
        int dul = (i >= n-1 ? INT_MAX : 2*dist_down[i][j] + dp[i+1][j][x-2]);
        int lewo = (j-1 < 0 ? INT_MAX : 2*dist_right[i][j-1] + dp[i][j-1][x-2]);
        dp[i][j][x] = min({gora,prawo,dul,lewo});
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << dp[i][j][k] << ' ';
    }
    cout << endl;
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