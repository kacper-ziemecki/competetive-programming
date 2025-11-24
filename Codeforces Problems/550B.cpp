#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll helper(ll i, ll n, ll l, ll r, ll d, vector<ll>& list, ll mn=1000000, ll mx=1, ll sm=0){
  if(i == n) return (l <= sm && sm <= r && mx-mn >= d);
  return helper(i+1,n,l,r,d,list,mn,mx,sm)+helper(i+1,n,l,r,d,list,min(mn,list[i]),max(mx,list[i]),sm+list[i]);
}

void solve()
{
  ll n,l,r,d;
  cin >> n >> l >> r >> d;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  cout << helper(0, n, l, r, d, list) << endl;
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