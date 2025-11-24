#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> list(n, 0);
  ll temp;
  for(ll i = 0; i < m; i++){
    cin >> temp;
    list[temp-1]++;
  }
  ll minimum = LONG_LONG_MAX;
  for(auto el : list){
    minimum = min(minimum, el);
  }
  cout << minimum << endl;
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