#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,d;
  cin >> n >> d;
  ll risk = 0, noRisk = 0;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp <= 9 || temp >= 80) risk++;
    else noRisk++;
  }
  cout << (risk+d-1)/d + (noRisk+d-1)/d << endl;
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