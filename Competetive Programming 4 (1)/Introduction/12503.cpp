#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  vector<string> list{};
  string temp;
  ll res = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp[0] == 'L')
    {
      list.push_back("LEFT");
      res--;
    }
    else if (temp[0] == 'R')
    {
      list.push_back("RIGHT");
      res++;
    }
    else
    {
      cin >> temp;
      cin >> temp;
      ll number = 0;
      ll power = 1;
      for (ll j = temp.size() - 1; j >= 0; j--)
      {
        number += (temp[j] - '0') * power;
        power *= 10;
      }
      if (list[number - 1][0] == 'L')
      {
        list.push_back("LEFT");
        res--;
      }
      else if (list[number - 1][0] == 'R')
      {
        list.push_back("RIGHT");
        res++;
      }
    }
  }
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

  ll t;
  cin >> t;
  while (t--)
    solve();
}