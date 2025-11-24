#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n, 0);
  ll res = 0;
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n; i++){
    if(list[i-1] + list[i] < k){
      res += k - (list[i-1] + list[i]);
      list[i] += k - (list[i-1] + list[i]);
    }
  }
  cout << res << endl;
  for(auto el : list) cout << el << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}