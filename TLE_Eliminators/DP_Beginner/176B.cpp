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

string s,t;
int k;
const int maxn = 1000;
int dp[maxn];
int suma1,suma2;
int mod = 1e9+7;
int res = 0;
int n;

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> t >> k;
  n = s.size();
  dp[0] = 1;
  suma2 = 1;
  for(int i = 1; i <= k; i++){
    suma1 = 0;
    for(int j = 0; j < n; j++){
      dp[j] = (suma2 - dp[j] + mod) % mod;
      suma1 = (suma1+dp[j]) % mod;
    }
    suma2 = suma1;
  }
  for(int i = 0; i < n; i++){
    if(s == t) res = (res + dp[i]) % mod;
    // cout << dp1[i] << ' ';
    s = s.back()+s.substr(0, n-1);
  }
  // cout << endl;
  cout << res << endl;
}