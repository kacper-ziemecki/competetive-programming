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
  ll n,t;
  cin >> n >> t;
  vector<ll> list(n),prefix(n);
  for(auto &el : list) cin >> el;
  prefix[0]=list[0];
  for(ll i = 1; i < n; i++) prefix[i] = list[i]+prefix[i-1];
  ll res=0;
  // for(auto el : prefix) cout << el << " ";
  // cout << endl;
  for(ll i = 0; i < n; i++){
    ll j = upper_bound(prefix.begin(), prefix.end(), (i == 0 ? 0 : prefix[i-1])+t)-prefix.begin();
    // dbg(i,j,j-i);
    res = max(res, j-i);
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

  solve();

}