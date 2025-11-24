#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string temp;
  n *= 2;
  map<char, ll> mapa;
  bool flag = true;
  for(ll i = 0; i < 4; i++){
    cin >> temp;
    for(auto el : temp) mapa[el]++;
    for(auto el : mapa){
      if(el.second > n && el.first != '.'){
        flag = false;
      }
    }
  }
  if(flag){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
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