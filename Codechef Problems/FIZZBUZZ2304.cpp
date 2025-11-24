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
  vector<ll> list(n);
  vector<bool> vis(n, false);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    if(list[i]&1) vis[i] = true;
  }
  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    if(vis[i]) cnt = k;
    cnt--;
    if(cnt >= 0) vis[i] = true;
  }
  ll res=0;
  for(ll i = k-1; i < n; i++){
    if(vis[i]) res++;
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