#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll x,y;
  cin >> x >> y;
  string text;
  cin >> text;
  vector<ll> list;
  ll temp = 0;
  for(auto el : text){
    if(el == '1'){
      temp++;
    }
    else{
      if(temp) list.push_back(temp);
      temp = 0;
    }
  }
  if(temp) list.push_back(temp);
  sort(list.rbegin(), list.rend());
  ll res = 0;
  for(ll i = 0; i < list.size(); i++){
    if(i == 0){
      res += list[i]*y;
    }
    res += list[i]*x;
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
  while(t--)
  solve();
}