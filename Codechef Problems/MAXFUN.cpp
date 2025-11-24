#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0ll);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  ll res = 0;
  for(ll i = 1; i < n-1; i++){
    res = max(res, abs(list[0]-list[i])+abs(list[i]-list[n-1])+abs(list[0]-list[n-1]));
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}