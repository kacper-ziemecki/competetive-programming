#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  ll suma = 0;
  vector<ll> list(n, 0);
  for (auto& el : list) {
    cin >> el;
    suma += el;
  }
  sort(list.begin(), list.end());
  ll temp = 0;
  for (ll i = n - 1; i >= 0; i--) {
    temp += list[i];
    suma -= list[i];
    if (temp > suma) {
      cout << n - i << endl;
      return;
    }
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