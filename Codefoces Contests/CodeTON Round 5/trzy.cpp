#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  vector<ll> dp(n, 0);
  map<ll, ll> mapa{};
  for(ll i = 0; i < n; i++){

    if(mapa[list[i]]){

      ll temp = dp[mapa[list[i]]-1];
      if(mapa[list[i]]-1 != 0 && dp[mapa[list[i]]-2] < dp[mapa[list[i]]-1]){
        temp += (i - mapa[list[i]] + 1);
      }
      else{
        temp += (i - mapa[list[i]] + 2);
      }

      dp[i] = max((i > 0 ? dp[i-1] : 0), temp);
    }

    else{
      dp[i] = (i > 0 ? dp[i-1] : 0);
    }
    mapa[list[i]] = i+1;
  }
  
  cout << dp[n-1] << endl;
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