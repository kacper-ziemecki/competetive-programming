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
  ll n,k,res=-1;
  cin >> n >> k;
  if((k*(k+1))/2 > n){ cout << -1 << endl; return; }
  for(ll i = 1; i*i <= n; i++){
    if(n%i == 0 && res < i && (k*(k+1))/2 * i <= n) res = i;
    if(n%i == 0 && res < n/i && (k*(k+1))/2 * (n/i) <= n) res = n/i;
  }
  cout << res << endl;
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