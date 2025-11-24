#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string one, two;
  cin >> one >> two;
  if((one[0] == 'b' || two[0] == 'b') && (one[1] == 'o'|| two[1] == 'o') && (one[2] == 'b' || two[2] == 'b')){
    cout << "yes\n";
  }
  else if((one[0] == 'o' || two[0] == 'o') && (one[1] == 'b' || two[1] == 'b') && (one[2] == 'b' || two[2] == 'b')){
    cout << "yes\n";
  }
  else if((one[0] == 'b' || two[0] == 'b') && (one[1] == 'b' || two[1] == 'b') && (one[2] == 'o' || two[2] == 'o')){
    cout << "yes\n";
  }
  else{
    cout << "no\n";
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