#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n)
{
  ll mini = LONG_LONG_MAX;
  vector<string> res(n, "");
  ll temp1;
  for (auto &el : res)
  {
    getline(cin, el);
    temp1 = 0;
    for (auto sub : el)
      if (sub == ' ')
        temp1++;

    mini = min(mini, temp1);
  }
  ll ans = 0;
  for (auto el : res)
  {
    temp1 = 0;
    for (auto sub : el)
      if (sub == ' ')
        temp1++;

    ans += temp1 - mini;
  }
  cout << ans << endl;
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
  string temp;
  while (true)
  {
    cin >> n;
    getline(cin, temp);
    if (n == 0)
      break;
    solve(n);
  }
}