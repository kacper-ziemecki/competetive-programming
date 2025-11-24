#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n)
{
  if (n == 0)
    return;
  ll temp;
  while (n >= 10)
  {
    temp = 0;
    while (n)
    {
      temp += n % 10;
      n /= 10;
    }
    n = temp;
  }
  cout << n << endl;
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