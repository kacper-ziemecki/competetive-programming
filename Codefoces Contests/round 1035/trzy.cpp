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


void solve()
{
  ll n,l,r,k;
  cin >> n >> l >> r >> k;
  if(n&1){ cout << l << endl; return; }
  if(n == 2){ cout << -1 << endl; return; }
  ll tmp = 1;
  while(tmp <= l) tmp <<= 1;
  if(tmp > r){ cout << -1 << endl; return; }

  if(k == n || k == n-1){
    cout << tmp << endl;
  } else{
    cout << l << endl;
  }
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}