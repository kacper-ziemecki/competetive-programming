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
  vector<ll> list(n), prefix(n, 0);
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n-1; i++){
    prefix[i] = prefix[i-1] + (list[i-1] < list[i] && list[i] > list[i+1] ? 1 : 0);
  }
  // for(auto el : prefix) cout << el << " ";
  // cout << endl;
  ll res = 0, left = 0;
  for(ll i = 0; i+k-2 < n; i++){
    if(prefix[i+k-2]-prefix[i] > res){
      res = prefix[i+k-2]-prefix[i];
      left = i;
    }
  }
  cout << res+1 << " " << left+1 << endl;
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