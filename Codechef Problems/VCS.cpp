#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,m,k;
  cin >> n >> m >> k;
  vector<ll> one(m, 0), two(k, 0);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  vector<bool> test1(n+1, false), test2(n+1, false);
  for(auto el : one){
    test1[el] = true;
  }
  for(auto el : two){
    test2[el] = true;
  }
  ll res1 = 0, res2 = 0;
  for(ll i = 1; i <= n; i++){
    if(test1[i] == true && test2[i] == true) res1++;
    if(test1[i] == false && test2[i] == false) res2++;
  }
  cout << res1 << " " << res2 << endl;
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