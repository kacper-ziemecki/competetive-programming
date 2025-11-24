#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n)
{
  vector<ll> first = { n }, second;
  ll temp;
  for (ll i = 1; i < 5; i++) {
    cin >> temp;
    first.push_back(temp);
  }
  for (ll i = 0; i < 5; i++) {
    cin >> temp;
    second.push_back(temp);
  }

  for (ll i = 0; i < 5; i++) {
    if (first[i] == second[i]) {
      cout << "N\n";
      return;
    }
  }
  cout << "Y\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll n;
  while (cin >> n) {
    solve(n);
  }
}