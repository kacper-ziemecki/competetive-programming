#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> list(n*m, 0);
  for(auto &el : list) cin >> el;
  sort(list.rbegin(), list.rend());
  ll one = 0, two = 0;
  for(ll i = 0; i < n*m; i++){
    if(i&1) two += list[i];
    else one += list[i];
  }
  
  if(one > two){
    cout << "Cyborg\n";
  }
  else if(one < two){
    cout << "Geno\n";
  }
  else{
    cout << "Draw\n";
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
  while(t--)
  solve();
}