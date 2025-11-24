#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n,a;
  cin >> n;
  vector<ll> list(1e5+1, 0);
  for(ll i = 0; i < n; i++){
    cin >> a;
    list[a]++;
  }
  for(ll i = 1; i < 1e5+1; i++){
    if(list[i]&1){
      cout << i << endl;
      return;
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
  while (t--)
    solve();
}