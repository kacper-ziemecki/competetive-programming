#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ll n;
  cin >> n;
  vector<ll> l(n, 0ll), res;
  map<ll, bool> m;
  for(auto &el : l) cin >> el;
  for(ll i = n-1; i >= 0; i--){
    if(!m[l[i]]){
      m[l[i]]=true;
      res.push_back(l[i]);
    }
  }
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  for(auto el : res) cout << el << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}