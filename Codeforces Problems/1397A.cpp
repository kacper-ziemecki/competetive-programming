#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<string> list(n, " ");
  for (auto& el : list) cin >> el;
  unordered_map<char, ll> test;
  for (auto text : list) {
    for (auto el : text) {
      test[el]++;
    }
  }
  for (auto el : test) {
    if (el.second % n != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
  while (t--) solve();

}