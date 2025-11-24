#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll test)
{
  ll one = 0, two = 0;
  ll n;
  cin >> n;
  ll temp;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp;
    one += (temp + 30) / 30 * 10;
    two += (temp + 60) / 60 * 15;
  }
  if (one < two)
  {
    cout << "Case " << test << ": Mile " << one << endl;
  }
  else if (one > two)
  {
    cout << "Case " << test << ": Juice " << two << endl;
  }
  else
  {
    cout << "Case " << test << ": Mile Juice " << two << endl;
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

  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++)
    solve(i);
}