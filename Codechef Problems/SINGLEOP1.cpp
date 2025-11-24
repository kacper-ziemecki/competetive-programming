#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  ll number = 0;
  for(ll i = 0; i < n; i++){
    number |= (text[i] == '1' ? 1<<(n-1-i) : 0);
  }

  ll res = 0;
  ll ans = 0;
  ll power = 1;
  for(ll i = 1; i <= text.size(); i++){
    power *= 2;
    if(res < (number ^ (number/power))){
      res = (number ^ (number/power));
      ans = i;
    }
  }
  cout << ans << endl;
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
  while(t--) solve();
}