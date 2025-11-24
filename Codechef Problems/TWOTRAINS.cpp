#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n-1, 0);
  for(auto &el : list) cin >> el;
  ll first = 0, second = 0;
  ll one = 0;
  for(ll two = 0; two < n-1; i++){
    while(one < two && first >= second){
      first += list[one];
      one++;
    }
    second += list[two];
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
  cin >> t;
  while(t--) solve();
}