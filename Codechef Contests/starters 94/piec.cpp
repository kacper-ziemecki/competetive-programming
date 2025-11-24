#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  ll total = 0;
  ll x = 0;
  ll res = 0;
  for(auto el : text){
    if(el == '4') total++;
    if(el == '*') x++;
  }
  ll right = total, left = 0;
  ll rightX = x, leftX = 0;
  for(auto el : text){
    if(el == '4'){
      left++;
      right--;
    }
    else if(el == '0'){
      res += left * right;
    }
    else if(el == '*'){
      res += (left * right) * pow(2, x-1); // kiedy zmieniamy na zero
      

      
      leftX++;
      rightX--;
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
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}