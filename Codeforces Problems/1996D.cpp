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
  ll n,x;
  cin >> n >> x;
  ll res = 0;
  for(ll a = 1; a <= n+x; a++){
    if(a+1+1 > x || a*1+a*1+1*1 > n) break;
    for(ll b = 1; b <= n+x; b++){
      if(a+b+1 > x || a*b+a*1+b*1 > n) break;
      ll l = 0, r = n+x;
      while(l < r){
        ll m = (l+r+1)/2;
        if(a+b+m<=x && a*b+a*m+b*m<=n) l = m;
        else r = m-1;
      }
      res += l;
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