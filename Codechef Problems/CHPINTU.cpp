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
  ll n,m;
  cin >> n >> m;
  vector<ll> one(n), two(n);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  map<ll, ll> mp;
  for(ll i = 0; i < n; i++){
    mp[one[i]]+=two[i];
  }
  ll res = LLONG_MAX;
  for(auto el : mp) res = min(res, el.second);
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