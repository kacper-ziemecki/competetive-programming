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

bool check(ll a, ll b, bool left=true){
  ll c;
  cout << "? " << a << " " << b << endl;
  cin >> c;
  return (left ? c==b : c==a);
}

void solve()
{
  ll n,x,idx;
  bool left = false;
  cin >> n;
  cout << "? 1 " << n << endl;
  cin >> idx;
  if(idx != 1){
    cout << "? 1 " << idx << endl;
    cin >> x;
    left = x==idx;
  }
  if(left){
    ll l = 1, r = idx-1;
    while(l < r){
      ll m = (l+r+1)/2;
      if(check(m, idx)) l = m;
      else r = m-1;
    }
    cout << "! " << l << endl;
  } else{
    ll l = idx+1, r = n;
    while(l < r){
      ll m = (l+r)/2;
      if(check(idx, m,false)) r = m;
      else l = m+1;
    }
    cout << "! " << r << endl;
  }

} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}