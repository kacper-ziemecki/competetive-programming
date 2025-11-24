#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  unordered_map<string, pair<ll, ll>> mapa;
  string a;
  ll b, c;
  for (ll i = 0; i < n; i++)
  {
    cin >> a >> b >> c;
    mapa[a] = {b, c};
  }
  ll m;
  cin >> m;
  for (ll i = 0; i < m; i++)
  {
    cin >> b;
    vector<string> res{};
    for (auto el : mapa)
    {
      if (b >= el.second.first && b <= el.second.second)
      {
        res.push_back(el.first);
      }
    }
    if (res.size() != 1)
      cout << "UNDETERMINED\n";
    else
      cout << res[0] << endl;
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

  ll t;
  cin >> t;
  while (t--)
  {
    solve();
    if (t != 0)
      cout << endl;
  }
}