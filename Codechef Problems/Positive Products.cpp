#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n;
  cin >> n;
  ll minus = -1, plus = -1;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp < 0) minus++;
    if(temp > 0) plus++;
  }
  minus = max(minus, 0ll);
  plus = max(plus, 0ll);
  cout << ((minus * (minus + 1))/2 + (plus * (plus + 1))/2) << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}