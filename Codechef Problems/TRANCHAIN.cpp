#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  map<string, ll> mapa;
  string temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    mapa[temp]++;
  }
  ll res = mapa["A"] + mapa["AB"];
  res = max(res, mapa["B"] + mapa["AB"]);
  res = max(res, mapa["AB"]);
  res = max(res, mapa["O"] + mapa["A"] + mapa["AB"]);
  res = max(res, mapa["O"] + mapa["B"] + mapa["AB"]);
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