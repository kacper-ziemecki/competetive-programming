#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll test)
{
  vector<ll> one(1001, 0), two(1001, 0), thre(1001, 0);
  vector<ll> first, second, third;
  ll n;
  cin >> n;
  ll temp;
  for (ll i = 0; i < n; i++) {
    cin >> temp;
    one[temp]++;
  }
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> temp;
    two[temp]++;
  }
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> temp;
    two[temp]++;
  }
  for (ll i = 1; i < 1001; i++) {
    if (one[i] != 0 && two[i] == 0 && thre[i] == 0) {
      first.push_back(i);
    }
    else if (two[i] != 0 &&)
  }

}

int main()


{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++) solve(i);
}