#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  ll m,c;
  cin >> m >> c;
  ll first = 0, second = 0;
  ll a,b,c1;
  for(ll i = 0; i < n; i++){
    cin >> a >> b >> c1;
    if(m*a + c < b){
      first += c1;
    }
    else{
      second += c1;
    }
  }
  cout << max(first, second) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
 
  solve();
}