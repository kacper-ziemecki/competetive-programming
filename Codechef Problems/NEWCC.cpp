#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a,b;
  cin >> a >> b;
  if(a < b){
    cout << "Old\n";
  }
  else if(a > b) {
    cout << "New\n";
  }
  else{
    cout << "Same\n";
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
  
  solve();
}