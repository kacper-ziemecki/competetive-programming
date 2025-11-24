#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  cin >> text;
  ll first = (text[0] - '0')*10 + (text[1] - '0');
  ll second = (text[3] - '0')*10 + (text[4] - '0');
  if(first > 12 && second <= 12){
    cout << "DD/MM/YYYY\n";
  }
  else if(first <= 12 && second > 12){
    cout << "MM/DD/YYYY\n";
  }
  else{
    cout << "BOTH\n";
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