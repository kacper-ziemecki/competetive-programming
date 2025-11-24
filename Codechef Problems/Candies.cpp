#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n,a;
  cin >> n;
  n*=2;
  unordered_map<ll, ll> list;
  for(ll i = 0; i < n; i++){
    cin >> a;
    list[a]++;
    if(list[a] > 2){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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