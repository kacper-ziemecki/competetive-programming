#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll,ll>> list(n, {0,0});
  for(auto &el : list) cin >> el.first >> el.second;
  ll temp = 0;
  for(auto el : list){
    ll x = max(0ll, (temp - el.first + el.second - 1) / el.second);
    if(el.first + el.second * x <= temp) x++;
    temp = el.first + el.second * x;
  }
  cout << temp << endl;
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