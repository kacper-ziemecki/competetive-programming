#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll a, ll b)
{
  cout << abs(b - a) << endl;
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

  ll a, b;
  while (cin >> a >> b)
    solve(a, b);
}