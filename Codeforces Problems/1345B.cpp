#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  ll res = 0;
  ll temp = 0;
  while(n > 1){
    res++;
    ll i = 1;
    while(n - 2*i >= 0){
      n -= 2 * i;
      if(n - i - 2 *(i+1) < 0){
        break;
      }
      n -= i;
      i++;
    }
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

  ll t;
  cin >> t;
  while(t--) solve();
}