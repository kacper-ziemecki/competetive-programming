#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> list(n, vector<ll>(6, 0));
  for(auto &sub : list){
    for(auto &el : sub){
      cin >> el;
    }
  }
  vector<ll> list1(n, 0);
  for(auto sub : list){
    
  }
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
  
 
  solve();
}