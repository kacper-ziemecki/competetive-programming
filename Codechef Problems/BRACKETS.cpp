#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  cin >> text;
  ll maxBalance = 0, balance = 0;
  for(auto el : text){
    if(el == '(') balance++;
    else balance--;
    maxBalance = max(maxBalance, balance);
  }
  for(ll i = 0; i < maxBalance; i++){
    cout << '(';
  }
  for(ll i = 0; i < maxBalance; i++){
    cout << ")";
  }
  cout << endl;
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