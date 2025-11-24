#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> ignore(m, 0);
  for(auto &el : ignore) cin >> el;
  vector<ll> list;
  ll index = 0;
  sort(ignore.begin(), ignore.end());
  for(ll i = 1; i <= n; i++){
    if(index < m && i == ignore[index]){
      index++;
      continue;
    }
    list.push_back(i);
  }
  vector<ll> one, two;
  for(ll i = 0; i < list.size(); i++){
    if(i&1){
      two.push_back(list[i]);
    }
    else{
      one.push_back(list[i]);
    }
  }
  // for(auto el : list) cout << el << ", ";
  // cout << endl;
  if(one.size() == 0) cout << -1;
  for(auto el : one) cout << el << " ";
  cout << endl;
  if(two.size() == 0) cout << -1;
  for(auto el : two) cout << el << " ";
  cout << endl;
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