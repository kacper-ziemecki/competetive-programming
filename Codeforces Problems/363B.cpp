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
  for(auto &el : list) cin >> el;
  ll suma = 0;
  for(ll i = 0; i < k; i++) suma += list[i];
  pair<ll, ll> res = {suma, 0};
  for(ll i = k; i < n; i++){
    suma -= list[i-k];
    suma += list[i];
    if(suma < res.first){
      res = {suma, i-k+1};
    }
  }
  cout << res.second+1 << endl;
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