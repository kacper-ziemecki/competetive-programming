#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n, ll test)
{
  vector<ll> list(n, 0);
  ll suma = 0;
  for (auto &el : list)
  {
    cin >> el;
    suma += el;
  }
  suma /= n;
  ll res = 0;
  for (auto &el : list)
  {
    res += max(0ll, el - suma);
  }
  cout << "Set #" << test << endl;
  cout << "The minimum number of moves is ";
  cout << res << "." << endl;
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

  ll n;
  ll test = 0;
  while (true)
  {
    test++;
    cin >> n;
    if (n == 0)
      break;
    solve(n, test);
    cout << endl;
  }
}