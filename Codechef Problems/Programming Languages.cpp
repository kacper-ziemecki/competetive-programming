#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  if(a == c && b == d){
    cout << 1 << endl;
  }
  else if(a == d && b == c){
    cout << 1 << endl;
  }
  else if(a == e && b == f){
    cout << 2 << endl;
  }
  else if(a == f && b == e){
    cout << 2 << endl;
  }
  else{
    cout << 0 << endl;
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
  while (t--)
    solve();
}