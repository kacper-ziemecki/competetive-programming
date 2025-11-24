#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c;
  cin >> a >> b >> c;
  if(a > 50){
    cout << "A\n";
  }
  else if(b > 50){
    cout << "B\n";
  }
  else if(c > 50){
    cout << "C\n";
  }
  else{
    cout << "NOTA\n";
  }
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