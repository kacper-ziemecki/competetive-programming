#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll a,b;
  cin >> a >> b;
  if(__gcd(a,a+1) > 1){
    cout << a << " " << a+1 << endl;
  }
  else if(__gcd(a,a+2) > 1 && b >= a+2){
    cout << a << " " << a+2 << endl;
  }
  else if(__gcd(a,a+3) > 1 && b >= a+3){
    cout << a << " " << a+3 << endl;
  }
  else if(__gcd(a+1,a+2) > 1 && b >= a+2){
    cout << a+1 << " " << a+2 << endl;
  }
  else if(a&1 && b >= a+3){
    cout << a+1 << " " << a+3 << endl;
  }
  else if(!(a&1) && b >= a+2){
    cout << a << " " << a+2 << endl;
  }
  else{
    cout << -1 << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}