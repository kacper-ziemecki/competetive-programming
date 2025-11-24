#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n)
{
  unordered_map<string, ll> mapa;
  vector<string> res(n, " ");
  string temp;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp;
    res[i] = temp;
    mapa[temp] = 0;
  }
  ll temp1, temp2;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp >> temp1 >> temp2;
    if (temp2 != 0)
    {
      mapa[temp] -= temp1 / temp2 * temp2;
    }

    for (ll j = 0; j < temp2; j++)
    {
      cin >> temp;
      mapa[temp] += temp1 / temp2;
    }
  }
  for (auto el : res)
  {
    cout << el << " " << mapa[el] << endl;
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

  ll n;
  ll i = 0;
  while (cin >> n)
  {
    i++;
    if (i != 1)
      cout << endl;
    solve(n);
  }
}