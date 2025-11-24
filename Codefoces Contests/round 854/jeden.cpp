#include <bits/stdc++.h>
using namespace std;

void solve()
{
  long long a, b, tmp;
  cin >> a >> b;
  unordered_map<long long, bool> mapa;
  vector<long long> lista(a, -1);
  for (long long i = 0; i < b; i++)
  {
    cin >> tmp;
    if (!mapa[tmp])
    {
      mapa[tmp] = true;
      lista[a - 1] = i + 1;
      a--;
    }
  }
  for (auto el : lista)
  {
    cout << el << " ";
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}