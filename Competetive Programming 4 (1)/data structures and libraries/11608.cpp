#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n, ll test)
{
  vector<ll> one(12, 0), two(12, 0);
  for (auto& el : one)
    cin >> el;
  for (auto& el : two)
    cin >> el;
  ll temp = n;
  cout << "Case " << test << ":\n";
  for (ll i = 0; i < 12; i++)
  {
    temp += (i > 0 ? one[i - 1] : 0);
    temp -= two[i];
    if (temp < 0)
    {
      cout << "No problem. :(\n";
      temp += two[i];
    }
    else
    {
      cout << "No problem! :D\n";
    }
  }
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
  ll test = 0;
  while (true)
  {
    test++;
    cin >> n;
    if (n < 0)
      break;
    solve(n, test);
  }
}