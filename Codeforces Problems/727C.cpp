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
  ll n,sum,x,y;
  cin >> n;
  vector<ll> sums(n-1), diff(n, 0);
  for(ll i = 0; i < n-1; i++){
    cout << "? " << i+1 << " " << i+2 << endl;
    cin >> sums[i];
  }

  cout << "? 1 3" << endl;
  cin >> sum;
  x = (sum-sums[1]+sums[0])/2;
  y = sums[0]-x;

  for(ll i = 0; i < n-2; i++){
    diff[i+2] = diff[i] + (sums[i+1]-sums[i]);
  }
  cout << "!";
  for(ll i = 0; i < n; i++){
    cout << " " << (i&1 ? y : x)+diff[i];
  }
  cout << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}