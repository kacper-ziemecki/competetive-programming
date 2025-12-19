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

int n;
int mod = 1e9+7;
ll dp1[4], dp2[4];

void solve(){
  cin >> n;
  dp2[3] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        if(j == k) continue;
        dp1[j] = (dp1[j] + dp2[k]) % mod;
      }
    }
    for(int j = 0; j < 4; j++){
      dp2[j] = dp1[j];
      dp1[j] = 0;
    }
  }
  cout << dp2[3] << endl;
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