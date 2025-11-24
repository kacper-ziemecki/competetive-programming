#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n;
  cin >> n;
  vector<ll> res(n, 0);
  if(n == 1){
    cout << 1 << endl;
    return;
  }
  else if(n == 2){
    cout << "2 1\n";
    return;
  }
  res[0] = 2;
  res[n-1] = 3;
  res[n/2] = 1;
  ll j = 0;
  for(ll i = 1; i <= n; i++){
    if(i == 1 || i == 2 || i == 3) continue;
    while(res[j] != 0) j++;
    res[j] = i;
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}