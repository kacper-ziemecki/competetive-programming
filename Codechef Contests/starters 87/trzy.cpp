#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 
long long binpow(long long a, long long b) {
    a %= 998244353;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % 998244353;
        a = a * a % 998244353;
        b >>= 1;
    }
    return res;
}
void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  vector<bool> flag(n, false);
  for(auto &el : list) cin >> el;
  ll maks = INT_MIN;
  for(int i = 0; i < n; i++){
    if(list[i] < maks){
      flag[i] = true;
    }
    maks = max(maks, list[i]);
  }
  ll minimum = INT_MAX;
  for(int i = n-1; i >= 0; i--){
    if(list[i] > minimum){
      flag[i] = true;
    }
    minimum = min(minimum, list[i]);
  }
  ll cnt = 0;
  for(auto el : flag){
    if(!el) cnt++;
  }
  if(cnt == n){
    cout << binpow(2, cnt) - 1<< endl;
  }
  else{
    cout << binpow(2, cnt)<< endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  ll t;
  cin >> t;
  while(t--) solve();
}