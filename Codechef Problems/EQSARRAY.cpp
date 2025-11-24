#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  if(list.size() == 1 && list[0] == k){
    cout << "Yes\n";
    return;
  }
  for(ll i = 0; i < n-1; i++){
    if(list[i] == k){
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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