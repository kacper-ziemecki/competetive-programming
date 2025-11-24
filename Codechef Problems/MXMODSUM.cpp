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
  ll n,m,res=0;
  cin >> n >> m;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end(), greater<>());
  for(ll i = 1; i < n; i++){
    res = max(res, list[i-1]+list[i]+max((list[i-1]-list[i])%m, (list[i]-list[i-1]+m)%m));
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