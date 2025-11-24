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
  string res = "";
  for(ll i = 0; i < n; i++){
    if(i&1){
      if(text[n - 1 - i/2] == '1'){
        res = '1' + res;
      }
      else{
        res += '0';
      }
    }
    else{
      if(text[i/2] == '1'){
        res += '1';
      }
      else{
        res = '0' + res;
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