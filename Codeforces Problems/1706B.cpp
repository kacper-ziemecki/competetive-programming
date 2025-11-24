#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  unordered_map<ll, vector<ll>> lista;
  set<ll> res;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    res.emplace(temp);
    if(!lista[temp].empty() && (i - lista[temp].back() - 1)&1){
      continue;
    }
    lista[temp].push_back(i);
  }
  for(ll i = 1; i <= n; i++){
    cout << (lista[i].empty() ? 0 : lista[i].size()) << " ";
  }
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

  ll t;
  cin >> t;
  while(t--) solve();
}