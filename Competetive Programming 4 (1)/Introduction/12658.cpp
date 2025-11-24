#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main()
{
  ll n;
  cin >> n;
  vector<string> list(5, "test");
  for (auto &el : list)
    cin >> el;
  string res = "";
  for (ll i = 0; i < n * 4; i += 4)
  {
    if (list[0][i] == '.')
    {
      res += '1';
    }
    else if (list[3][i] == '*')
    {
      res += '2';
    }
    else
    {
      res += '3';
    }
  }
  cout << res << endl;
}