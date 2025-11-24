#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int a, b;
  cin >> a >> b;
  if (max(a, b) == 1)
  {
    cout << "1/1\n";
  }
  if (max(a, b) == 2)
  {
    cout << "5/6\n";
  }
  if (max(a, b) == 3)
  {
    cout << "2/3\n";
  }
  if (max(a, b) == 4)
  {
    cout << "1/2\n";
  }
  if (max(a, b) == 5)
  {
    cout << "1/3\n";
  }
  if (max(a, b) == 6)
  {
    cout << "1/6\n";
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