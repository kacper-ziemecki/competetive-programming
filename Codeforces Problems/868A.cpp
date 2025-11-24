#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string wzor;
  cin >> wzor;
  ll n;
  cin >> n;
  vector<string> list(n, " ");
  for(auto &el : list) cin >> el;
  for(auto el : list){
    if(el == wzor){
      cout << "YES\n";
      return;
    }
    if(el[0] == wzor[1] && el[1] == wzor[0]){
      cout << "YES\n";
      return;
    }
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(i != j && list[i][1] == wzor[0] && list[j][0] == wzor[1]){
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
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