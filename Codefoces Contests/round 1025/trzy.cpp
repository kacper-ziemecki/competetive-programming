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
  ll n,res;
  cin >> n;
  for(ll i = 0; i < 2; i++){
    cout << "digit" << endl;
    cout.flush();
    cin >> res;
  }
  ll l = 0, r = 14;
  while(l < r){
    ll m = (l+r+1)/2;
    cout << "add " << -m << endl;
    cout.flush();
    cin >> res;
    if(!res){
      r = m-1;
    } else{
      r = max(0ll, r-m);
    }
  }
  cout << "add " << n-1 << endl;
  cout.flush();
  cin >> res;
  cout << "!" << endl;
  cout.flush();
  cin >> res;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  ll t;
  cin >> t;
  while(t--)
  solve();
}