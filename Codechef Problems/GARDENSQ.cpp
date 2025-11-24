#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> list(n, "");
  for(auto &el : list) cin >> el;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      ll size = 1;
      while(i+size < n && j+size < m){
        if(list[i][j] == list[i+size][j] && list[i][j] == list[i][j+size] && list[i][j] == list[i+size][j+size]){
          res++;
        }
        size++;
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