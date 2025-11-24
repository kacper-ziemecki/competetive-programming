#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> jeden(n, 0), dwa(n, 0);
  for (auto &el : jeden)
    cin >> el;
  for (auto &el : dwa)
    cin >> el;
  int cnt = 0, maks = 0;
  for (int i = 0; i < n; i++)
  {
    if (jeden[i] && dwa[i])
    {
      cnt++;
      maks = max(maks, cnt);
    }
    else
      cnt = 0;
  }
  cout << maks << "\n";
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