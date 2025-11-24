#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll one = 0, two = 0, three = 0;
  for(auto el : list){
    if(el == 1) one++;
    if(el == 2) two++;
    if(el == 3) three++;
  }
  ll res = one+two;
  res = min(res, one+three);
  res = min(res, two+three);
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