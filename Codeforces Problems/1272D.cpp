#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n), prefix(n, 1), suffix(n, 1);
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n; i++){
    prefix[i] = (list[i] > list[i-1] ? prefix[i-1]+1 : 1);
    suffix[n-i-1] = (list[n-i-1] < list[n-i] ? suffix[n-i]+1 : 1);
  }

  // for(auto el : prefix) cout << el << " ";
  // cout << endl;
  // for(auto el : suffix) cout << el << " ";
  // cout << endl;

  ll res = 0;
  for(ll i = -1; i < n+1; i++){
    res = max(res, i-1 >= 0 ? prefix[i-1] : 0);
    if((i-1 >= 0 ? list[i-1] : 0) >= (i+1 < n ? list[i+1] : ULLONG_MAX)) continue;
    ll cur = (i-1 >= 0 ? prefix[i-1] : 0) + (i+1 < n ? suffix[i+1] : 0);
    res = max(res, cur);
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