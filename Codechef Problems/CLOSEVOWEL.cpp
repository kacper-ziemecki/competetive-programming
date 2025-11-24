#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  string wzor = "aeiou";
  ll res = 1;
  for(auto el1 : text){
    vector<ll> list(5, 0);
    for(ll i = 0; i < 5; i++){
      list[i] = abs(el1 - wzor[i]);
    }
    sort(list.begin(), list.end());
    if(list[0] != 0){
      cout << el1 << endl;
      for(auto el : list) cout << el << " ";
      cout << endl;
      for(ll i = 1; i < 5; i++){
        if(list[i-1] == list[i]){
          res *= 2;
          break;
        }
      }
    }
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}