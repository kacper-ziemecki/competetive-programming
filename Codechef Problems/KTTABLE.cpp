#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, res = 0;
  cin >> n;
  vector<int> jeden(n, 0), dwa(n, 0);
  for (auto &el : jeden)
    cin >> el;
  for (auto &el : dwa)
    cin >> el;
  for (int i = 0; i < n; i++)
  {
    if (jeden[i] - (i != 0 ? jeden[i - 1] : 0) >= dwa[i])
      res++;
  }
  cout << res << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}