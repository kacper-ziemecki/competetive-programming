#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
	ll n;
  cin >> n;
  if(n <= 3){
    cout << "BRONZE\n";
  }
  else if(n <= 6){
    cout << "SILVER\n";
  }
  else if(n > 6){
    cout << "GOLD\n";
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