#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n, 0ll), b(n, 0ll);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  ll tmp = -1;
  for(ll i = 0; i < n; i++){
    if(a[i] < b[i]){
      cout << "NO\n";
      return;
    }
    if(a[i] != 0 && b[i] != 0){
      tmp = a[i] - b[i];
    }
  }
  if(tmp == -1){
    cout << "YES\n";
    return;
  }
  for(ll i = 0; i < n; i++){
    if(a[i] != 0 && b[i] != 0 && (a[i] - b[i] != tmp)){
      cout << "NO\n";
      return;
    }
    if((a[i] == 0 || b[i] == 0) && (a[i]-b[i] > tmp)){
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

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
}