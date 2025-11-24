#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

bool prime(ll n){
  for(ll i = 2; i*i < n; i++){
    if(n%i == 0) return false;
  }
  return true;
}

void solve()
{
	ll x,y;
  cin >> x >> y;
  ll res = 0;
  if(x&1){
    res++;
    for(ll i = 3; i <= x; i++){
      if(x%i == 0 && prime(i)){
        x += i;
        break;
      }
    }
  } 
  res += (y-x+1)/2;
  cout << res << endl;
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