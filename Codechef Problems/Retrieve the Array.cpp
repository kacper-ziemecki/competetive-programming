#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n;
  cin >> n;
  ll suma = 0;
  vector<ll> list(n, 0);
  for(auto &el : list){
    cin >> el;
    suma += el;
  }
  suma /= n+1;
  for(auto el : list){
    cout << el-suma << " ";
  }
  cout << endl;
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