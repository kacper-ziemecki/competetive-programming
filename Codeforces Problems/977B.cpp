#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  unordered_map<string, ll> mapa;
  for (ll i = 1; i < n; i++) {
    string temp;
    temp += text[i - 1];
    temp += text[i];
    mapa[temp]++;
  }
  pair<string, ll> res = { "  ", 0 };
  for (auto el : mapa) {
    if (el.second > res.second) {
      res = el;
    }
  }
  cout << res.first << endl;
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