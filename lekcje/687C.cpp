#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,k;
const int maxN = 502, maxSum = 501*501;
short coins[maxN];
bitset<20> dp[maxN], vis[maxN];
set<int> res;

int helper(int id, int sum){
  if(id < 0 || sum < 0) return 0;
  if(bit[id][sum]) return bit[id][sum];
  return bit[id][sum] = helper(id-1, sum) | helper(id-1, sum-coins[id-1]);
}

void solve()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> coins[i];
  dp[0][0] = 1;
  helper(n, k);
  for(int i = 0; i <= n; i++) cout << dp[i].to_string() << endl;
  
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}