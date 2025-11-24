#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string country;
  cin >> country;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    string temp1;
    cin >> temp1;
    if(temp1 == "CONTEST_WON"){
      ll temp2;
      cin >> temp2;
      res += 300 + max(0ll, 20ll - temp2);
    }
    else if(temp1 == "TOP_CONTRIBUTOR"){
      res += 300;
    }
    else if(temp1 == "BUG_FOUND"){
      ll temp2;
      cin >> temp2;
      res += temp2;
    }
    else{
      res += 50;
    }
  }
  if(country == "INDIAN"){
    cout << res/200 << endl;
  }
  else{
    cout << res/400 << endl;
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
  while(t--) solve();
}