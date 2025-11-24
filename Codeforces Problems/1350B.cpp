#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> divisors(ll n){
  vector<ll> res;
  for(ll i = 1; i*i <= n; i++){
    if(n%i) continue;
    if(i != n) res.push_back(i);
    if(i != n/i && n/i != n) res.push_back(n/i);
  }
  return res;
}

void solve()
{
  ll n,res=0;
  cin >> n;
  vector<ll> list(n), dp(n, 1);
  for(auto &el : list) cin >> el;
  for(ll i = 1; i <= n; i++){
    vector<ll> ind = divisors(i);
    for(auto j : ind){
      if(list[i-1] <= list[j-1]) continue;
      dp[i-1] = max(dp[i-1], dp[j-1]+1);
    }
    res = max(res, dp[i-1]);
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();  
  
} 