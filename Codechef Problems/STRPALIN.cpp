#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string one, two;
  cin >> one >> two;
  map<char, bool> mapa;
  for(auto el : one) mapa[el] = true;
  for(auto el : two){
    if(mapa[el]){
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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