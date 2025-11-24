#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m,x,y;
  cin >> n >> m >> x >> y;
  string res(n, '0');
  string candidate;
  for(ll i = 0; i < n; i++){
    cin >> candidate;
    ll solved = 0, partially = 0;
    for(auto el : candidate){
      if(el == 'F') solved++;
      if(el == 'P') partially++;
    }
    if(solved >= x || (solved == x-1 && partially >= y)){
      res[i] = '1';
    }
  }
  cout << res << endl;
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
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}