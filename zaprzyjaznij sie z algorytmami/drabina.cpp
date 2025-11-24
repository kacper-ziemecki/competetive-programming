#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll s,p;
  cin >> s >> p;
  ll mod = 1 << p;
  ll first = 1%mod, second = 2%mod;
  if(s == 1){
    cout << first << endl;
    return;
  }
  ll temp;
  for(ll i = 2; i < s; i++){
    temp = first;
    first = second;
    first %= mod;
    second += temp;
    second %= mod;
  }
  

  cout << second << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
//   freopen("../../output.txt", "w", stdout);
// #endif

  ll t;
  cin >> t;
  while(t--) solve();
}