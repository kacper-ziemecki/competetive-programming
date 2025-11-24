#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int n;
  cin >> n;
  vector<int> list(n, 0);
  for (auto &el : list)
    cin >> el;
  sort(list.begin(), list.end());
  int res = INT_MAX;
  for (int i = 1; i < n; i++)
    res = min(res, list[i] - list[i - 1]);
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

  int t;
  cin >> t;
  while (t--)
    solve();
}