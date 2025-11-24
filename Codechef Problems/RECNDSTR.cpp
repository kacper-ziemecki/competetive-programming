#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  cin >> text;
  string one,two;
  one = text.substr(1, text.size()-1) + text[0];
  two = text.back() + text.substr(0, text.size()-1);
  // cout << one << " " << two << endl;
  if(one == two){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
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