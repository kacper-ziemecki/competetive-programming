#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  int a=0,b=0;
  string text;
  cin >> text;
  for(auto el : text){
    if(el == '1') a++;
    if(el == '0') b++;
  }
  if(a % 2 == 0 || b % 2 == 0){
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
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}