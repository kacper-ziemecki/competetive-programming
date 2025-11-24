```c++
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll int
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
ll n,q,a,b,c;
const ll maxN = 1e5+1, d = 316;
ll lista[maxN], dp[maxN][2];

void solve()
{
  cin >> n >> q;
  for(ll i = 0; i < n; i++) cin >> lista[i];
 
  for(ll left = 0; left < n; left+= d){
    ll right = min(n-1, left+d-1);
    for(ll i = right; i >= left; i--){
      if(i+lista[i] > right){
        dp[i][0] = 1;
        dp[i][1] = i;
      } else{
        dp[i][0] = dp[i+lista[i]][0]+1;
        dp[i][1] = dp[i+lista[i]][1];
      }
    }
  }
 
  for(ll i = 0; i < q; i++){
    cin >> a;
    if(a){
      cin >> b;
      b--;
      ll count = 0;
      ll last = b;
      while(b < n){
        count += dp[b][0];
        last = dp[b][1];
        b = dp[b][1] + lista[dp[b][1]];
        if(b < n ) last = b;
      }
      cout << last+1 << " " << count << endl;
    } else{
      cin >> b >> c;
      b--;
      lista[b] = c;
      // x*d <= b 
      // x <= b/d
      ll x = b/d;
      ll left = x*d;
      ll right = min(n-1, (x+1)*d-1);
      for(ll i = right; i >= left; i--){
        if(i+lista[i] > right){
          dp[i][0] = 1;
          dp[i][1] = i;
        } else{
          dp[i][0] = dp[i+lista[i]][0]+1;
          dp[i][1] = dp[i+lista[i]][1];
        }
      }
    }
  }
}
  
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  solve();
}
```