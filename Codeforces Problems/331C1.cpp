#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

ll check(ll n){
  ll maks = 0;
  while(n){
    maks = max(maks, n%10);
    n/=10;
  }
  return maks;
}


void solve()
{
  ll n;
  cin >> n;
  ll res = 0;
  while(n){
    res++;
    n -= check(n);
  }
  cout << res << endl;
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