#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n,q,t1,t2;
  cin >> n >> q;
  vector<ll> a(n, 0), b(n, 0), prefix(n, 0);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  prefix[0] = a[0]*b[0];
  for(ll i = 1; i < n; i++){
    prefix[i] = prefix[i-1] + a[i]*b[i];
  }
  for(ll i = 0; i < q; i++){
    cin >> t1 >> t2;
    cout << prefix[t2-1] - (t1-2 >= 0 ? prefix[t1-2] : 0) << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  solve();
}