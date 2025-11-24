#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,a,b;
  cin >> n >> a >> b;
  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    cnt += (a>>i)&1;
  }
  for(ll i = 0; i < n; i++){
    cnt += (b>>i)&1;
  }
  if(cnt > n){
    cnt = n - (cnt-n);
  }
  ll res = 0;
  for(ll i = n-1; i >= n-cnt; i--){
    res |= (1<<i);
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