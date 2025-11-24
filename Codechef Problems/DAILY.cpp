#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

ll fact(ll n){
  ll res = 1;
  for(ll i = 2; i <= n; i++){
    res *= i;
  }
  return res;
}

void solve()
{
  ll x,n;
  cin >> x >> n;
  vector<vector<ll>> carts(9, vector<ll>(6, 0));
  ll first = 0;
  ll second = 55;
  for(auto &el : carts){
    for(ll i = 0; i < 4; i++){
      first++;
      el.push_back(first);
    }
    for(ll i = 0; i < 2; i++){
      second--;
      el.push_back(second);
    }
  }
  vector<string> list(n, " ");
  for(auto &el : list) cin >> el;
  ll res = 0;
  for(auto el : list){
    for(auto cart : carts){
      ll temp = 0;
      for(auto chair : cart){
        if(el[chair-1] == '0') temp++;
      }
      if(temp >= x){
        res += fact(temp) / (fact(temp - x) * fact(x));
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
  
  solve();
}