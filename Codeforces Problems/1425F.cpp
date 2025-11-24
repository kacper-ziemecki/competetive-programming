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
  ll n,sum,x,prev;
  cin >> n;
  cout << "? 1 " << n << endl;
  cin >> sum;
  vector<ll> list(n);
  prev = sum;
  for(ll i = 2; i < n; i++){
    cout << "? " << i << " " << n << endl;
    cin >> x;
    list[i-2] = prev-x;
    prev = x;
  }
  cout << "? 1 " << n-1 << endl;
  cin >> x;
  list[n-1] = sum-x;
  list[n-2] = prev - list[n-1];
  cout << "!";
  for(auto el : list) cout << " " << el;
  cout << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}