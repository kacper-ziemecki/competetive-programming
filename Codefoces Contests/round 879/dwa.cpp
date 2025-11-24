#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  string one, two;
  cin >> one >> two;
  ll res = 0;

  while(one.size() < two.size()){
    one = '0' + one;
  }
  while(two.size() < one.size()){
    two = '0' + two;
  }
  ll n = one.size();
  ll index = n;
  for(ll i = 0; i < n; i++){
    if(abs((one[i] - '0') - (two[i] - '0')) >= 1){
      index = i;
      break;
    }
  }
  for(ll i = n-1; i > 0; i--){
    if(i > index){
      res += 9;
    }
    else{
      res += abs((one[i] - '0') - (two[i] - '0'));
    }
  }
  res += abs((one[0] - '0') - (two[0] - '0'));
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