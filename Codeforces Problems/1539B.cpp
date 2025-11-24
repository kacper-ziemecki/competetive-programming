#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n, q;
  cin >> n >> q;
  string text;
  cin >> text;
  vector<ll> prefix_sums(n, 0);
  prefix_sums[0] = text[0] - 'a' + 1;
  for (int i = 1; i < n; i++)
  {
    prefix_sums[i] = prefix_sums[i - 1] + text[i] - 'a' + 1;
  }
  ll a, b;
  for (int i = 0; i < q; i++)
  {
    cin >> a >> b;

    cout << prefix_sums[b - 1] - (a - 2 < 0 ? 0 : prefix_sums[a - 2]) << endl;
  }
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

  solve();
}