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
  sort(list.begin(), list.end());
  ll res = 0;
  for(auto el : list){
    if((el - list[0])%k != 0){
      cout << -1 << endl;
      return;
    }
    res += (el - list[0])/k;
  }
  cout << res << endl;
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