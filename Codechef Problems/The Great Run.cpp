#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n,k,res=0,temp=0;
  cin >> n >> k;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i <= n-k; i++){
    temp=0;
    for(ll j = i; j < i+k && j < n; j++){
      temp+= list[j];
    }
    res = max(res, temp);
  }
  cout << res << endl;
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