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
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<ll> list{a,b,c};
  sort(list.begin(), list.end());
  ll res = 0;
  res += min(d-1, list[0])*3;
  list[1] -= min(d-1, list[0]);
  list[2] -= min(d-1, list[0]);
  d -= min(d-1, list[0]);
  // dbg(res, d);
  res += min(d-1, list[1])*2;
  list[2] -=min(d-1, list[1]);
  d -= min(d-1, list[1]);
  // dbg(res, d);
  res += min(d-1, list[2])*1;
  d -= min(d-1, list[2]);
  // dbg(res, d);
  res+=1;
  // dbg(res);
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