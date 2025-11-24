#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> res(n, 0), list(m, 0);
  for(auto &el : list) cin >> el;
  ll last = INT_MAX;
  for(auto el : list){
    if(el < last){
      res[el-1] = el;
      last = el;
    }
  }
  last = res[0];
  for(ll i = 0; i < n; i++){
    if(res[i] != 0){
      last = res[i];
    }
    res[i] = last;
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
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