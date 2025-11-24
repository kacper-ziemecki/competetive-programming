#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<vector<ll>> dp;

ll subsolve(ll i, vector<ll>& list, ll sum){
  if(i==list.size() || sum==0) return 0;
  if(dp[i][sum]) return dp[i][sum];
  if(list[i] > sum) return dp[i][sum]=subsolve(i+1, list, sum);
  return dp[i][sum]=max(subsolve(i+1, list, sum), list[i]+subsolve(i+1, list, sum-list[i]));
}

void solve(){
  ll n,sum=0;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  for(auto el : list) sum += el;
  dp.assign(n, vector<ll>(sum/2+1,0));
  ll res = subsolve(0, list, sum/2);
  cout << abs(res - (sum-res)) << endl;
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
  
  ll t;
  cin >> t;
  while(t--) solve();
}