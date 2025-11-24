#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(long double a, long double b, long double c, long double d)
{
  unordered_map<long double, long double> mapa;
  long double one, two;
  for (ll i = 0; i < d; i++)
  {
    cin >> one >> two;
    mapa[one] = two;
  }
  long double owes = c, value = c;
  long double last = 0;
  for (auto el : mapa)
    cout << el.first << " -> " << el.second << endl;

  for (long double i = 0; i <= a; i++)
  {
    if (mapa[i])
    {
      cout << mapa[i] * value << " val?\n";
      value = value * (1 - mapa[i]);
      last = i;
    }
    else
    {
      cout << mapa[last] * value << " val?\n";
      value = (1 - mapa[last]) * value;
    }
    cout << owes << " " << value << endl;

    if (owes < value && i != 0)
    {
      cout << i << " months\n";
      return;
    }
    owes -= b;
  }
  cout << "not ended\n";
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

  long double a, b, c, d;
  while (true)
  {
    cin >> a >> b >> c >> d;
    if (a < 0)
      break;
    solve(a, b, c, d);
  }
}