#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
	ll n,d,h;
  cin >> n >> d >> h;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll res = 0;
  for(auto el : list){
    if(el == 0){
      res = max(res-d, 0ll);
    }
    else{
      res += el;
    }

    if(res > h){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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