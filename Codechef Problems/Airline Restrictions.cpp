#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  if(a+b <= d && c <= e){
    cout << "YES\n";
  }
  else if(a+c <= d && b <= e){
    cout << "YES\n";
  }
  else if(b+c <= d && a <= e){
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
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}