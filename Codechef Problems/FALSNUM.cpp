#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
	string text;
  cin >> text;
  ll n = text.size();
  if(text[0] != '1'){
    cout << '1' + text << endl;
  }
  else{
    for(ll i = 1; i < n; i++){
      if(text[i] != '0'){
        cout << text.substr(0,i) + '0' + text.substr(i, n-i+1) << endl;
        return;
      }
      
    }
    cout << text + '0' << endl;
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
  while(t--)
  solve();
}