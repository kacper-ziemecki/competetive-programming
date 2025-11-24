#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)




void solve()
{
  ll n,k,q,d;
  cin >> n >> k >> q;
  vector<ld> a(k), b(k);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(ll i = 0; i < q; i++){
    cin >> d;
    ll idx = (upper_bound(a.begin(), a.end(), d) - a.begin())-1;
    ld dist_before = (idx<0 ? 0 : a[idx]);
    ld time_before = (idx<0 ? 0 : b[idx]);
    ld dist_after = a[min(k-1, idx+1)];
    ld time_after = b[min(k-1, idx+1)];
    ld res = time_before + (time_after-time_before == 0 ? 0 : (d - dist_before)*(time_after-time_before)/(dist_after-dist_before));
    // dbg(idx,time_before,dist_before,time_after,dist_after);
    cout << fixed << setprecision(0) << floor(res) << " ";
  }
  cout << endl;
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