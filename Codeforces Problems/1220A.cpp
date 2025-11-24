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
  ll one = 0, zero = 0;
  for (auto el : text) {
    if (el == 'z') zero++;
    if (el == 'n') one++;
  }
  for (ll i = 0; i < one; i++) {
    cout << "1 ";
  }
  for (ll i = 0; i < zero; i++) {
    cout << "0 ";
  }
  cout << endl;
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