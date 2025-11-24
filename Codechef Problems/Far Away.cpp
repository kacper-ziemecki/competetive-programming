#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll a,b,c,res=0;
  cin >> a >> b;
  for(ll i = 0; i < a; i++){
    cin >> c;
    res += max(abs(c-1), abs(c-b));
  }
  cout << res << endl;
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