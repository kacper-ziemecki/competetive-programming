#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,q;
  cin >> n >> q;
  vector<pair<ll, ll>> list(q, {0, 0});
  for(auto &el : list) cin >> el.first >> el.second;
  ll res = 0, cur = 0;
  for(auto el : list){
    // cout << el.first << " " << el.second << endl;
    res += abs(cur - el.first);
    cur = el.first;
    res += abs(cur - el.second);
    cur = el.second;
    // cout << res << endl;
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