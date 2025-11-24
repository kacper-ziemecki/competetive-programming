#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  sort(list.rbegin(), list.rend());
  ll sum = 0;
  for(ll i = 0; i < n; i++){
    sum += list[i];
    if(sum >= m){
      cout << i+1 << endl;
      return;
    }
  }
  cout << -1 << endl;
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