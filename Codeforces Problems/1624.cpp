#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int n;
  cin >> n;
  int temp, maks = 0, minimum = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    maks = max(maks, temp);
    minimum = min(minimum, temp);
  }
  cout << maks - minimum << endl;
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

  int t;
  cin >> t;
  while (t--)
    solve();
}