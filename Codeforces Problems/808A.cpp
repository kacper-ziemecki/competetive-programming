#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,f=1;
  cin >> n;
  string temp = to_string(n);
  ll power = 1;
  for(ll i = 1; i < temp.size(); i++){
    power *= 10;
  }
  ll res = n % power;
  cout << power - res << endl;
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