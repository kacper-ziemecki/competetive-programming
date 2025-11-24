#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n;
  cin >> n;
  string one, two;
  cin >> one >> two;

  if(one == two){
    cout << 0 << endl;
    return;
  }

  ll first = 0, second = 0;
  for(ll i = 0; i < n; i++){
    if(one[i] != two[i]) first++;
  }

  if(first == 1){
    cout << 1 << endl;
    return;
  }

  for(ll i = 0; i < n; i++){
    if(one[i] != two[n-i-1]) second++;
  }

  ll res1 = first + (first&1 ? first-1 : first);
  ll res2 = second + (second&1 ? second : (second == 0 ? 2 : second-1));
  cout << min(res1, res2) << endl;
  
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}