#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n), bits(31,0);
  for(auto &el : list) cin >> el;
  for(auto el : list){
    for(ll i = 0; i < 31; i++){
      if((el>>i)&1) bits[i]++;
    }
  }
  for(auto& el : bits) el = n-el;
  ll res = 0;
  for(ll i = 30; i >= 0; i--){
    if(bits[i] <= k){
      res += 1<<i;
      k -= bits[i];
    }
  }
  cout << res << endl;
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