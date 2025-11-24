#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n)
{
  ll res = 0;
  ll temp;
  for (ll i = 0; i < 5; i++)
  {
    cin >> temp;
    if (temp == n)
      res++;
  }
  cout << res << endl;
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
  while (cin >> n)
    solve(n);
}