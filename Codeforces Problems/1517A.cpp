#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ull n;
  cin >> n;
  ull number = (ull)2050 * (ull)1e15;
  ull res = 0;
  while(n > 0){
    while(number > 2050 && number > n){
      number /= 10;
    }
    if(n < number){
      cout << -1 << endl;
      return;
    }
    n -= number;
    res++;
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}