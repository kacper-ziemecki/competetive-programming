#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  string text;
  cin >> text;
  int a = 0, b=0;
  for(auto el : text){
    if(el == '0') a++;
    if(el == '1') b++;
  }
  cout << min(a+1, b) << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}