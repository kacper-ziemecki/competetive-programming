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

const int maxn = 1e3+1;
int n,m;
ll lista[maxn][maxn];
ll dp1[maxn][maxn];
ll dp2[maxn][maxn];
ll dp3[maxn][maxn];
ll dp4[maxn][maxn];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> lista[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      dp1[i][j] = lista[i][j] + max((i-1 < 0 ? 0 : dp1[i-1][j]) , (j-1 < 0 ? 0 : dp1[i][j-1]));
    }
  }
  for(int i = n-1; i >= 0; i--){
    for(int j = m-1; j >= 0; j--){
      dp2[i][j] = lista[i][j] + max((i+1 >= n ? 0 : dp2[i+1][j]) , (j+1 >= m ? 0 : dp2[i][j+1]));
    }
  }
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < m; j++){
      dp3[i][j] = lista[i][j] + max((i+1 >= n ? 0 : dp3[i+1][j]) , (j-1 < 0 ? 0 : dp3[i][j-1]));
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = m-1; j >= 0; j--){
      dp4[i][j] = lista[i][j] + max((i-1 < 0 ? 0 : dp4[i-1][j]) , (j+1 >= m ? 0 : dp4[i][j+1]));
    }
  }
  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     cout << dp1[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  ll res = INT_MIN;
  for(int i = 1; i < n-1; i++){
    for(int j = 1; j < m-1; j++){
      res = max(res, (j-1 < 0 ? 0 : dp1[i][j-1])+(j+1 >= m ? 0 : dp2[i][j+1])+(i+1 >= n ? 0 : dp3[i+1][j])+(i-1 < 0 ? 0 : dp4[i-1][j]));
      res = max(res, (i-1 < 0 ? 0 : dp1[i-1][j])+(i+1 >= n ? 0 : dp2[i+1][j])+(j-1 < 0 ? 0 : dp3[i][j-1])+(j+1 >= m ? 0 : dp4[i][j+1]));
      // dbg(res, i, j);
    }
  }
  cout << res << endl;
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