#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  ll one = 0, two = 0, three = 0;
  ll cntOne = 0, cntTwo = 0, cntThree = 0;
  ll temp = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp < 0)
    {
      one += abs(temp) - 1;
      cntOne++;
    }
    if (temp > 0)
    {
      two += abs(temp) - 1;
      cntTwo++;
    }
    if (temp == 0)
    {
      three++;
      cntThree++;
    }
  }
  if (cntOne % 2 == 0)
  {
    cout << one + two + three << endl;
  }
  else if (cntThree >= 1)
  {
    cout << one + two + three << endl;
  }
  else
  {
    cout << one + two + three + 2 << endl;
  }
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

  solve();
}