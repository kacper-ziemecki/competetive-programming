#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  if(n <= 10){
    cout << "Lower Double\n";
  }
  else if(n <= 15){
    cout << "Lower Single\n";
  }
  else if(n <= 25){
    cout << "Upper Double\n";
  }
  else{
    cout << "Upper Single\n";
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