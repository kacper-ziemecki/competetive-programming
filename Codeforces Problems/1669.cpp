#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  // For Division 1 : 1900≤rating
  // For Division 2 : 1600≤rating≤1899
  // For Division 3 : 1400≤rating≤1599
  // For Division 4 : rating≤1399
  int n;
  cin >> n;
  if (1900 <= n)
  {
    cout << "Division 1\n";
  }
  if (1600 <= n && n <= 1899)
  {
    cout << "Division 2\n";
  }
  if (1400 <= n && n <= 1599)
  {
    cout << "Division 3\n";
  }
  if (1399 >= n)
  {
    cout << "Division 4\n";
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

  int t;
  cin >> t;
  while (t--)
    solve();
}