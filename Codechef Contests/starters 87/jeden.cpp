#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll a,b;
  cin >> a >> b;
  if(a*a*a*a + 4*b*b == 4*a*a*b){
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
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}