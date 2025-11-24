#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

ll compute(pair<ll,ll> one, pair<ll, ll> two){
  if(one.first <= two.first && one.second <= two.second){
    return min(two.first - one.first, one.second - one.first)
  }
  else if(two.first <= one.first && two.second <= one.second){

  }

  else if(one.first <= two.first && one.second >= two.second){

  }
  else if(two.first <= one.first && two.second >= one.second){

  }
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> list(n, {0, 0});
  for(auto &el : list) cin >> el.first >> el.second;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      res = max(res, compute(list[i], list[j]));
    }
  }
  cout << res << endl;
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