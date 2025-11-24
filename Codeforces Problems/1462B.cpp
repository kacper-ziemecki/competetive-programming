#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  string text, wzor = "2020";
  cin >> text;
  ll flag1 = 0, flag2 = 0;
  for (int i = 0; i < 4; i++)
  {
    if (text[i] != wzor[i])
      break;
    flag1++;
  }
  for (int i = 0; i < 4; i++)
  {
    if (text[n - i - 1] != wzor[3 - i])
      break;
    flag2++;
  }

  cout << (flag1 + flag2 >= 4 ? "YES\n" : "NO\n");
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while (t--)
    solve();
}