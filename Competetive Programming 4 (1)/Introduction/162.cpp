#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(vector<string> list)
{
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

  while (true)
  {
    vector<string> list(52, " ");
    cin >> list[0];
    if (list[0] == "#")
      break;
    for (ll i = 1; i < 52; i++)
    {
      cin >> list[i];
    }
    solve(list);
  }
}