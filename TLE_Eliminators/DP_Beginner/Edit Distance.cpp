#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
// #define endl "\n"
=======
#define endl "\n"
>>>>>>> 952e7c21049b9109c75bef0824521f94fc3c7717
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

<<<<<<< HEAD
const int maxn = 5002;
int dp[maxn][maxn];
int n,m;
string a,b;

int helper(int i, int j){
  if(i == -1 && j == -1) return 0;
  if((i == -1 && j != -1) || (i != -1 && j == -1)) return abs(i-j);
  if(dp[i][j] != -1) return dp[i][j];
  int res = INT_MAX-1;
  //addition
  res = min(res, helper(i, j-1)+1);
  //removal
  res = min(res, helper(i-1,j)+1);
  //replacement
  res = min(res, helper(i-1,j-1)+1);

  if(a[i] == b[j]) res = min(res, helper(i-1,j-1));
  // dbg(i,j,res);
  return dp[i][j] = res;
}
void solve(){
  cin >> a >> b;
  n = a.size();
  m = b.size();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) dp[i][j] = -1;
  }
  cout << helper(n-1,m-1) << endl;
=======

const int maxn = 5000;


void solve(){

>>>>>>> 952e7c21049b9109c75bef0824521f94fc3c7717
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

<<<<<<< HEAD
// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif
=======
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
>>>>>>> 952e7c21049b9109c75bef0824521f94fc3c7717

  solve();
}