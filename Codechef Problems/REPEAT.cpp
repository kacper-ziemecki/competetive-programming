#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,k,s;
  cin >> n >> k >> s;
  ll suma = 0;
  ll i = 0;
  ll el = -1;
  while(i < n){
    i++;
    el+= 2;
    suma += el;
  }
  s -= suma;
  s /= k-1;
  cout << s << endl;
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