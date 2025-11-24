#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  if((a+b+c+d+e)*f <= 24*5){
    cout << "No\n";
  }
  else{
    cout << "Yes\n";
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