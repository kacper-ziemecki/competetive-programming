#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  map<ll, ll> mapa;
  for(auto el : list){
    if(el == 5){
      mapa[5]++;
    }
    else if(el == 10 && mapa[5] > 0){
      mapa[10]++;
      mapa[5]--;
    }
    else if(el == 15){
      if(mapa[10] > 0){
        mapa[10]--;
      }
      else if(mapa[5] >= 2){
        mapa[5] -= 2;
      }
      else{
        cout << "NO\n";
        return;
      }
    }
    else{
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
  while(t--)
  solve();
}