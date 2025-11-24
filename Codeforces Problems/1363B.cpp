#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  string s;
  cin >> s;
  ll n = s.size();
  vector<ll> prefix_sums(n, 0);
  prefix_sums[0] = s[0]=='1' ? 1 : 0;
  for(ll i = 1; i < n; i++){
    prefix_sums[i] = prefix_sums[i-1] + (s[i]=='1' ? 1 : 0);
  }
  ll res = min(prefix_sums[n-1],n-prefix_sums[n-1]);
  for(ll i = 0; i < n; i++){
    ll cur1 = ((i+1)-prefix_sums[i]) + (prefix_sums[n-1]-prefix_sums[i]);
    ll cur2 = prefix_sums[i] + ((n-i-1)-(prefix_sums[n-1]-prefix_sums[i]));
    res = min({res, cur1, cur2});
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