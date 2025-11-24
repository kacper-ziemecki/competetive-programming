#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double


void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> one(n, 0), two(n, 0);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  ull sum1 = 0;
  ull sum2 = 0;
  for(ll i = 0; i < n; i++){
    sum1 += (two[i] == 1 ? one[i] : 0);
  }
  for(ll i = 0; i < k; i++){
    sum2 += (two[i] == 0 ? one[i] : 0);
  }
  ull res = sum1;
  for(ll i = k-1; i < n; i++){
    res = max(res, sum1 + sum2);
    sum2 -= (two[i-k+1] == 0 ? one[i-k+1] : 0);
    sum2 += (two[i+1] == 0 ? one[i+1] : 0);

  }
  
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}