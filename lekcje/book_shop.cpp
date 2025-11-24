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

ll n,x;
const ll maxN = 1e3+1, maxX = 1e5+1;
vector<ll> h,s;

ll helper(ll id, ll rest){
  if(rest < 0) return INT_MIN;
  if(id < 0 && rest < 0) return INT_MIN;
  if(id < 0 && rest >= 0) return 0;
  if(dp[id][rest] != -1) return dp[id][rest];

  return dp[id][rest] = max(helper(id-1,rest), s[id]+helper(id-1, rest-h[id]));
}

void solve()
{
  cin >> n >> x;
  h.resize(n); s.resize(n);
  for(auto &el : h) cin >> el;
  for(auto &el : s) cin >> el;
  for(ll id = 0; id < n; id++){
    for(ll rest = 0; rest <= x; rest++) dp[id][rest] = -1;
  }
  cout << helper(n-1, x) << endl;  
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}