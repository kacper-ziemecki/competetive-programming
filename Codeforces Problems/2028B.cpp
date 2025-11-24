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
  ll n,b,c,res=0;
  cin >> n >> b >> c;
  res += min(n,c);
  n -= min(n, c);
  if(b > 0){
    dbg((b-1)*((n-1)/b), (n-(b*((n-1)/b))));
    res += (b-1)*((n-1)/b) + (n-(b*((n-1)/b)));
  } else{

  }
  dbg(res);
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