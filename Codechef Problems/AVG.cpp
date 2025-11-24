#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,k,v;
  cin >> n >> k >> v;
  ll sum = 0;
  ll a;
  for(ll i = 0; i < n; i++){
    cin >> a;
    sum += a;
  }
  v *= n+k;
  if(((v - sum)%k != 0) || (v - sum <= 0)){
    cout << -1 << endl;
  }
  else{
    cout <<  ((v - sum)/k) << endl;
  }
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
  while(t--) solve();
}