#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(vector<ll>& list)
{
  ll n;
  cin >> n;
  for (ll i = 0; i < list.size(); i++) {
    if (list[i] > n) {
      cout << i << endl;
      return;
    }
  }
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


  unordered_map<ll, bool> test{};
  vector<ll> res{};
  for (ll i = 1; i <= 1e5; i++) {
    res.push_back(i * i);
    test[i * i] = true;
  }
  for (ll i = 1; i <= 1e3; i++) {
    if (!test[i * i * i]) {
      res.push_back(i * i * i);
    }
  }

  sort(res.begin(), res.end());

  ll t;
  cin >> t;
  while (t--) {
    solve(res);
  }
}