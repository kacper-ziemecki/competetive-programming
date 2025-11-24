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
  for(auto &el : list) cin >> el;
  ld suma = 0;
  for(auto el : list) suma += el;
  ld mean = suma/n;
  ll i = 0;
  for(auto el : list){
    i++;
    if(mean == (suma-el)/(n-1)){
      cout << i << endl;
      return;
    }
  }
  cout << "Impossible\n";
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