#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> one(n, 0), two(n, 0), three(n, 0);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  // sort(one.begin(), one.end()); 
  // sort(two.begin(), two.end());
  ll suma = 0, res = 0;
  for(ll i = 0; i < n; i++){
    three[i] = one[i] - two[i];
    suma += three[i];
    res += abs(three[i]);
  }
  if(suma == 0){
    cout << res/2 << endl;
  }
  else{
    cout << -1 << endl;
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