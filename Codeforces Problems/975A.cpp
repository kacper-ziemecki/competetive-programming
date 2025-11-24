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
  string temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    set<char> temp1;
    for(auto el : temp) temp1.emplace(el);
    string res = "";
    for(auto el : temp1) res += el;
    mapa[res] = true;
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