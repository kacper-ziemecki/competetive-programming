#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int q,k,a;
char sign;
const int maxK = 5e3+1;
int dp[maxK];

void solve()
{
  cin >> q >> k;
  dp[0] = 1;
  for(int i = 0; i < q; i++){
    cin >> sign >> a;
    if(sign == '+'){
      for(int i = a; i <= k; i++) dp[i] += dp[i-a];
    } else{
      for(int i = a; i <= k; i++) dp[i] -= dp[i-a];
    }
    cout << dp[k] << endl;
  }
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}