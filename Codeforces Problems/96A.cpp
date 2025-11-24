#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  cin >> text;
  ll cnt = 1;
  for (ll i = 1; i < text.size(); i++) {
    if (text[i] == text[i - 1]) cnt++;
    else cnt = 1;
    if (cnt >= 7) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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