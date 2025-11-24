#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

long double maximum(long double a, long double b)
{
  if (a > b)
    return a;
  return b;
}

void solve(long double h, long double u, long double d, long double f)
{
  long double res = 0;
  long double now = 0;
  f *= u / 100;
  while (now >= 0 && now <= h)
  {
    res++;
    now += u;
    if (now > h)
      break;
    now -= d;
    if (res >= 1)
    {
      u -= f;
      u = maximum(u, 0);
    }
  }
  if (now > h)
    cout << "success on day " << res << endl;
  else
  {
    cout << "failure on day " << res << endl;
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

  long double h, u, d, f;
  while (true)
  {
    cin >> h >> u >> d >> f;
    if (h == 0)
      break;
    solve(h, u, d, f);
  }
}