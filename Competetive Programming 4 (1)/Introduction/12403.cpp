#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll &sum)
{
  string text;
  cin >> text;
  if (text[0] == 'r')
  {
    cout << sum << endl;
  }
  else
  {
    ll n;
    cin >> n;
    sum += n;
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
  ll sum = 0;
  cin >> t;
  while (t--)
    solve(sum);
}