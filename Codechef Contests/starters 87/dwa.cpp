#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll x;
  cin >> x;
  if(x == 1){
    cout << -1 << endl;
  }
  else if(x == 2){
    cout << "1 1 1\n";
  }
  else{
    if(x <= 1e6){
      cout << x-1 << " " << 1 << " " << 1 << endl;
    }
    else{
      ll a = 1e6, b = (x/1e6);
      ll c = x - (a*b);
      if(c == 0){
        b = (x/1e6) - 1;
        c = x - (a*b);
      }

      cout << a << " " << b << " " << c << endl;
    }
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