#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> first(n, 0), second(n, 0);
  for(auto &el : first) cin >> el;
  for(auto &el : second) cin >> el;
  ll res = 0, one = 0, two = 0, temp = 0;
  for(ll i = 0; i < n; i++){
    if((first[i] + second[i]) > ((one|first[i]) + (two|second[i]))){
      temp = first[i] + second[i];
      one = first[i];
      two = second[i];
    }
    else{
      temp = (one|first[i]) + (two|second[i]);
      one |= first[i];
      two |= second[i];
    }
    res = max(res, temp);
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