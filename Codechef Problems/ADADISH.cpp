#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void subsolve(vector<ll> list, ll i, ll jeden, ll dwa, ll &res){
  if(i == list.size()) return;
  res = min(res, max(jeden-list[i], dwa+list[i]));
  subsolve(list, i+1, jeden-list[i], dwa+list[i], res);
  subsolve(list, i+1, jeden, dwa, res);
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll res = INT_MAX;
  ll suma = 0;
  for(auto el : list) suma += el;
  subsolve(list, 0, suma, 0, res);
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