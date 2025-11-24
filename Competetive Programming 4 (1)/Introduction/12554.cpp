#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  vector<string> list(n, "");
  for (auto &el : list)
    cin >> el;
  vector<string> wzor = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
  ll i = 0;
  bool flag = false;
  while (true)
  {
    if (i == n)
      flag = true;

    if ((i % (wzor.size()) == 0) && flag && i > 0)
      break;

    cout << list[i % n] << ": " << wzor[i % (wzor.size())] << endl;
    i++;
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