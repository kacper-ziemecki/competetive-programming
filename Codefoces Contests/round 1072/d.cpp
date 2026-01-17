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

const int maxn = 31, maxk = 61;
int n,k;
int dp[maxn][maxk];

int cost(int x){
  int res = 0;
  while(x){
    if(x&1) x--;
    else x >>= 1;
    res++;
  }
  return res;
}


void solve(){
  cin >> n >> k;
  int z = -1;
  while(n){
    z++;
    n >>= 1;
  }
  if(k >= 60){
    cout << 0 << endl;
    return;
  }
  int res = 0;
  for(int i = 0; i <= z; i++){
    for(int j = 1; j <= k; j++){
      res += dp[i][j];
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

  dp[0][1] = 1;
  for(int i = 1; i < maxn; i++){
    for(int j = 1; j < maxk; j++){
      dp[i][j] += dp[i-1][j]; //mnozymy razy 2
      dp[i][j] += dp[i][j-1]; //dodajemy 1
      if(cost(1<<i) == j-1) dp[i][j]--; //ostatni
    }
    dp[i][cost(1<<(i-1))]--;
  }

  int t;
  cin >> t;
  while(t--)
  solve();
}