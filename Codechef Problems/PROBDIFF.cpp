#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  set<ll> list;
  ll a;
  for(ll i = 0; i < 4; i++){
    cin >> a;
    list.emplace(a);
  }
  ll other = list.size(); 
  if(other == 4 || other == 3){
    cout << 2 << endl;
  }
  else if(other == 2){
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
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