#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0), b(n, 0);
  for (auto &el : a)
    cin >> el;
  for (auto &el : b)
    cin >> el;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  int suma = 0;
  for (int i = 0; i < min(k, n); i++)
  {
    if (a[i] < b[i])
    {
      a[i] = b[i];
    }
  }
  for (auto el : a)
    suma += el;
  cout << suma << endl;
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