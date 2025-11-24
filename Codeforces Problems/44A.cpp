#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  unordered_map<string, bool> mapa;
  string one, two;
  for(ll i = 0; i < n; i++){
    cin >> one >> two;
    mapa[one + " " + two] = true;
  }
  cout << mapa.size() << endl;
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