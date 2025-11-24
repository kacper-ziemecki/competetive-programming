#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> res(n, vector<ll>(n, 0));
  ll tmp = 1;
  for(ll i = 0; i < n; i++){
    if(i & 1){
      for(ll j = n-1; j>= 0; j--){
        res[i][j] = tmp++;
      }
    }
    else{
      for(ll j = 0; j < n; j++){
        res[i][j] = tmp++;
      }
    }
  }
  for(auto sub : res){
    for(auto el : sub){
      cout << el << " ";
    }
    cout << endl;
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
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}