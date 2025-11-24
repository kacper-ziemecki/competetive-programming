#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll i)
{
  ll a = 0, b = 0;
  ll temp;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp > 0)
      a++;
    else
      b++;
  }
  cout << "Case " << i << ": " << a - b << endl;
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
  ll i = 0;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;
    i++;
    solve(n, i);
  }
}