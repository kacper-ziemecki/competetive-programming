#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> list(n, 0), suffix(n, 0);
  for(auto &el : list) cin >> el;
  set<ll> zbior;
  for(ll i = n-1; i >= 0; i--){
    zbior.emplace(list[i]);
    suffix[i] = zbior.size();
  }
  ll temp;
  for(ll i = 0; i < m; i++){
    cin >> temp;
    cout << suffix[temp-1] << endl;
  }
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