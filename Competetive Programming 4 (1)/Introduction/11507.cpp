#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n)
{
  ll res1 = 0, res2 = 0, res3 = 0;
  string temp;
  for (ll i = 0; i < n - 1; i++)
  {
    cin >> temp;
    if (temp == "+z")
      res3++;
    if (temp == "-z")
      res3--;
    if (temp == "+y")
      res2++;
    if (temp == "-y")
      res2--;
    if (temp == "+x")
      res1++;
    if (temp == "-x")
      res1--;
  }
  res1 %= 4;
  res2 %= 4;
  res3 %= 4;
  cout << res1 << " " << res2 << " " << res3 << endl;
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
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;
    solve(n);
  }
}