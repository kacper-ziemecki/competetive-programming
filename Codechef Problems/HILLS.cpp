#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,u,d;
  cin >> n >> u >> d;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  bool flag = true;
  for(ll i = 1; i < n; i++){
    if(list[i-1]+u < list[i]){
      cout << i << endl;
      return;
    }
    else if(list[i-1]-d > list[i] && !flag){
      cout << i << endl;
      return;
    }
    else if(list[i-1]-d > list[i] && flag){
      flag = false;
    }
  }
  cout << n << endl;
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