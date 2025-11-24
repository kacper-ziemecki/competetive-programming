#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<string> l(n, " ");
  for(auto &el : l) cin >> el;
  pair<ll, ll> one, two;
  bool flag = false;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(l[i][j] == '*' && !flag){
        one = {i, j};
        flag = true;
      } else if(l[i][j] == '*' && flag){
        two = {i, j};
      }
    }
  }
  if(one.first == two.first){
    if(one.first == 0){
      l[one.first+1][one.second] = '*';
      l[two.first+1][two.second] = '*';
    } else{
      l[one.first-1][one.second] = '*';
      l[two.first-1][two.second] = '*';
    }
  } else if(one.second == two.second){
    if(one.second == 0){
      l[one.first][one.second+1] = '*';
      l[two.first][two.second+1] = '*';
    } else{
      l[one.first][one.second-1] = '*';
      l[two.first][two.second-1] = '*';
    }
  } else{
    l[two.first][one.second] = '*';
    l[one.first][two.second] = '*';
  }
  for(auto el : l) cout << el << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}