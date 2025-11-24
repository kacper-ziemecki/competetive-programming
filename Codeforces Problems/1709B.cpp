#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> list(n, 0), prefix(n, 0), suffix(n, 0);
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n; i++){
    prefix[i] = prefix[i-1] + max(0ll, list[i-1] - list[i]);
  }
  for(ll i = n-2; i >= 0; i--){
    suffix[i] = suffix[i+1] + max(0ll, list[i+1] - list[i]);
  }
  cout << endl;
  ll a,b;
  for(ll i = 0; i < m; i++){
    cin >> a >> b;
    if(b > a) cout << prefix[b-1] - prefix[a-1] << endl;
    else cout << abs(suffix[a-1] - suffix[b-1]) << endl;
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