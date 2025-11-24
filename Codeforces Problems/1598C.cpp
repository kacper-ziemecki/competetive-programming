#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ld n;
  cin >> n;
  vector<ld> list(n, 0);
  map<ld, ll> mapa;
  ld suma = 0;
  for(auto &el : list){
    cin >> el;
    mapa[el]++;
    suma += el;
  }
  suma /= n;
  ll res = 0;
  for(auto el : list){
    res += (suma + (suma - el) != el ? mapa[suma + (suma - el)] : mapa[suma + (suma - el)] - 1);
  }
  cout << res/2 << endl;
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

  ll t;
  cin >> t;
  while(t--) solve();
}