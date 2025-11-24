#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

bool test(ll n){
  string liczba = to_string(n);
  for(ll i = 0; i < liczba.size()/2; i++){
    if(liczba[i] != liczba[liczba.size()-1-i]) return false;
  }
  return true;
}
void solve()
{
  ll a,b;
  cin >> a >> b;
  ll res = 0;
  for(ll i = a; i <= b; i++){
    if(test(i)) res+=i;
  }
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
  while(t--) solve();
}