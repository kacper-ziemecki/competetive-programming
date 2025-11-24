#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(i == 0){
      list.push_back(temp);
    }
    else if((list.back() < 0 && temp > 0) || (list.back() > 0 && temp < 0)){
      list.push_back(temp);
    }
    else if(list.back() > 0 && temp > 0 && temp > list.back()){
      list.pop_back();
      list.push_back(temp);
    }
    else if(list.back() < 0 && temp < 0 && temp > list.back()){
      list.pop_back();
      list.push_back(temp);
    }
  }
  ll res = 0;
  for(auto el : list){
    res += el;
  }
  cout << res << endl;
  
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

  ll t;
  cin >> t;
  while(t--) solve();
}