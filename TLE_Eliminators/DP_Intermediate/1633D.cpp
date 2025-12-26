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

const int maxb = 1e3+1, maxk = 1e6+1;
int cost[maxb];
int dp[maxk];
int n,k;
int res = 0;

void solve(){
  cin >> n >> k;
  vector<int> b(n), c(n);
  for(auto &el : b) cin >> el;
  for(auto &el : c) cin >> el;
  for(auto &el : b) el = cost[el];
  for(int sum = 0; sum <= k; sum++) dp[sum] = 0;

  dp[b[0]] = c[0];
  res = max(0, (b[0] <= k ? c[0] : 0));

  for(int id = 1; id < n; id++){
    for(int sum = k; sum >= 0; sum--){
      dp[sum] = max(dp[sum], (sum-b[id] < 0 ? 0 : dp[sum-b[id]]+c[id]));
    }
  }
  for(int sum = 0; sum <= k; sum++) res=max(res, dp[sum]);
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

  for(int i = 0; i < maxb; i++) cost[i] = INT_MAX;
  cost[1] = 0;
  for(int i = 1; i < maxb; i++){
    for(int j = 1; j <= i; j++){
      if(i+(i/j) >= maxb) continue;
      cost[i+(i/j)] = min(cost[i+(i/j)],cost[i]+1);
    }
  }

  int t;
  cin >> t;
  while(t--)
  solve();
}