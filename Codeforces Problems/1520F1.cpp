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


bool check(ll m, ll k){
  cout << "? 1 " << m << endl;
  ll x;
  cin >> x;
  return (m-x) >= k;
}

void solve()
{
  ll n,t,k;
  cin >> n >> t >> k;
  ll l = 1, r = n;
  while(l < r){
    ll m = (l+r)/2;
    if(check(m,k)) r = m;
    else l = m+1;
  }
  cout << "! " << r << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}