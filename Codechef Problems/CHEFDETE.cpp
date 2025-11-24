#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n+1, 0);
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp) list[temp]++;
  }
  for(ll i = 1; i < n+1; i++){
    if(list[i] == 0) cout << i << " ";
  }
  cout << endl;
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