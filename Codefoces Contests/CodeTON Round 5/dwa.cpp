#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,x;
  cin >> n >> x;
  vector<ll> one(n, 0), two(n, 0), three(n, 0);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  for(auto &el : three) cin >> el;
  ll res = 0;
  for(auto el : one){
    if(((res|el) | x) != x) break;
    res |= el;
  }
  for(auto el : two){
    if(((res|el) | x) != x) break;
    res |= el;
  }
  for(auto el : three){
    if(((res|el) | x) != x) break;
    res |= el;
  }
  if(res == x){
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
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}