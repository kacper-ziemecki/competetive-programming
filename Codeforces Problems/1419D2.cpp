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
  ll n;
  cin >> n;
  vector<ll> list(n), res1(n), res2(n);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end(), greater<ll>());
  for(ll i = 0; i < n; i++){
    if(!(i&1)) res1[i] = list[i/2];
    else res1[i] = list[((n+1)/2)+i/2];
  }
  for(ll i = 0; i < n; i++){
    if(i&1) res2[i] = list[i/2];
    else res2[i] = list[(n/2)+i/2];
  }
  ll ans1 = 0, ans2 = 0;
  for(ll i = 1; i < n-1; i++){
    if(res1[i-1] > res1[i] && res1[i+1] > res1[i]) ans1++;
    if(res2[i-1] > res2[i] && res2[i+1] > res2[i]) ans2++;

  }
  if(ans1 > ans2){
    cout << ans1 << endl;
    for(auto el : res1) cout << el << " ";
    cout << endl;
  } else{
    cout << ans2 << endl;
    for(auto el : res2) cout << el << " ";
    cout << endl;
  }
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

  solve();
}