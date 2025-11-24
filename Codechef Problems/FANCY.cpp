#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  getline(cin, text);
  ll n = text.size();
  if(text == "not"){
    cout << "Real Fancy\n";
    return;
  }
  else if(text.size() > 3){
    if(text.substr(0, 4) == "not "){
      cout << "Real Fancy\n";
      return;
    }
    else if(text.substr(n-4, 4) == " not"){
      cout << "Real Fancy\n";
      return;
    }
    else{
      for(ll i = 0; i+5 < n; i++){
        if(text.substr(i, 5) == " not "){
          cout << "Real Fancy\n";
          return;
        }
      }
    }
  }
  cout << "regularly fancy\n";
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
  string temp;
  getline(cin, temp);
  while(t--)
  solve();
}