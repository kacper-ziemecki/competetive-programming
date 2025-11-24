#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll a, ll b, ll i)
{
  if (b * 26 + b < a)
  {
    cout << "Case " << i << ": impossible\n";
    return;
  }
  ll res = 0;
  ll temp = b;
  while (b < a)
  {
    res++;
    b += temp;
  }
  cout << "Case " << i << ": " << res << endl;
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

  ll a, b, i = 0;
  while (true)
  {
    i++;
    cin >> a >> b;
    if (a == 0 && b == 0)
      break;
    solve(a, b, i);
  }
}