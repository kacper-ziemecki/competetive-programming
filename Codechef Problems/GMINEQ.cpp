#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  ll one = 0, two = 0;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp == -1) one++;
    else two++;
  }
  if((one == 1 && n >= 4) || (two == 1 && n >= 4)){
    cout << "No\n";
  }
  else if(one == two){
    cout << "Yes\n";
  }
  else if(one > two && one-2 <= two){
    cout << "Yes\n";
  }
  else if(one < two && two-2 <= one){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
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