#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{

  ll n;
  cin >> n;
  vector<ll> list1(n, 0);
  for(auto &el : list1) cin >> el;

  ll m;
  cin >> m;
  vector<ll> list2(m, 0);
  for(auto &el : list2) cin >> el;

  ll first = 0, second = 0;
  ll one = 0, two = 0;
  for(ll i = 0; i < n; i++){
    one += list1[i];
    first = max(first, one);
  }
  for(ll i = 0; i < m; i++){
    two += list2[i];
    second = max(second, two);
  }
  cout << first + second << endl;
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

  ll t;
  cin >> t;
  while(t--) solve();
}