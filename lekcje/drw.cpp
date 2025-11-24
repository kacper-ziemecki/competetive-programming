#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,sum=0,res=0;
const int maxN = 1e6+1, maxSum=5;
vector<int> lista;
int dp[maxN][maxSum];

void solve()
{
  // cin >> n;
  // lista.resize(n);
  // for(int i = 0; i < n; i++){
  //   cin >> lista[i];
  //   sum += lista[i];
  // }
  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j < maxSum; j++) dp[i][j] = -1;
  // }
  // sort(lista.begin(), lista.end());
  // dp[0][0] = 0;
  // for(int i = 1; i <= n; i++){
  //   for(int j = 0; j < maxSum; j++){
  //     dp[i][j] = dp[i-1][j];
  //     if(j-lista[i-1] >= 0 && dp[i-1][j-lista[i-1]] != -1) dp[i][j] = lista[i-1];
  //   }
  // }

  // // for(int i = 0; i <= n; i++){
  // //   for(int j = 0; j <= sum; j++) cout << dp[i][j] << " ";
  // //   cout << endl;
  // // }
  // // cout << endl;

  // for(int i = 1; i < maxSum; i++){
  //   if(i-dp[n][i] <= sum-i) res = i;
  // }
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

}