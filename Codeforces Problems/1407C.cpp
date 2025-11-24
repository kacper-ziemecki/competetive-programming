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
  ll n,a,b;
  cin >> n;
  ll mx = 1;
  vector<ll> res(n, n);
  for(ll i = 2; i <= n; i++){
    cout << "? " << i << " " << mx << endl; cin >> a;
    cout << "? " << mx << " " << i << endl; cin >> b;
    if(a > b){
      res[i-1] = a;
    } else{
      res[mx-1] = b;
      mx = i;
    }
  }
  cout << "! ";
  for(auto el : res) cout << el << " ";
  cout << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}