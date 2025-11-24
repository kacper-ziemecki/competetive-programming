#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  ll one = 0, two = 0, temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp == 2) one++;
    if(temp == 0) two++;
  }
  ll res = (one * (one-1)) / 2;
  res += (two * (two-1)) / 2;
  cout << res << endl;
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
  while(t--)
  solve();
}