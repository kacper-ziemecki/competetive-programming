#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,k;
vector<ll> candies;

ll helper(ll id, ll rest){
  if(rest == 0) return 1;
  if(id < 0) return 0;
  ll res = 0;
  for(ll i = 0; i <= min(rest, candies[id]); i++){
    res += helper(id-1, rest - i);
  }
  return res;
}

void solve()
{
  cin >> n >> k;
  candies.resize(n);
  for(ll i = 0; i < n; i++) cin >> candies[i];
  cout << helper(n-1,k) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}