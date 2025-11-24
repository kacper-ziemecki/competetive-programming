#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

bool check(ll n, ll d){
  while(n){
    if(n%10 == d) return true;
    n /= 10;
  }
  return false;
}

void solve()
{
  ll q,d;
  cin >> q >> d;
  vector<ll> list(q, 0);
  for(auto &el : list) cin >> el;
  for(auto &el : list){
    while(!check(el, d) && el >= d){
      el -= d;
    }
    if(check(el, d)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}