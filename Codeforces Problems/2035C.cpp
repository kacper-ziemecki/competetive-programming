#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n;
  cin >> n;
  if(n&1){
    cout << n << endl;
    for(ll i = 1; i <= n; i++){
      if(i == n || i == n-1 || i == 1) continue;
      cout << i << " ";
    }
    cout << 1 << " " << n-1 << " " << n << endl;
  } else{
    ll res = 1;
    while(res<<1 <= n) res <<= 1;
    cout << (res|(res-1)) << endl;
    for(ll i = 1; i <= n; i++){
      if(i == res || i == res-1 || i == res-2 || i == 1) continue;
      if(res == n && i == n-3) continue;
      if(res < n && i == n-1) continue;
      cout << i << " ";
    }
    if(res == n) cout << n-3 << " ";
    else cout << n-1 << " ";
    cout << 1 << " " << res-2 << " " << res-1 << " " << res << endl;
  }
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