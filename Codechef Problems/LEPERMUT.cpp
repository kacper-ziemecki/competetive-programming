#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll local = 0, global = 0;
  for(ll i = 1; i < n; i++){
    if(list[i] < list[i-1]) local++;
  }
  for(ll i = 0; i < n-1; i++){
    for(ll j = i+2; j < n; j++){
      if(list[i] > list[j]){
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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