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

ll helper(ll l, ll r, vector<ll>& list){
  if(l+1==r) return 0;
  ll m = (l+r)/2;
  ll mxLeft=LLONG_MIN, mnLeft=LLONG_MAX;
  ll mxRight=LLONG_MIN, mnRight=LLONG_MAX;
  for(ll i = l; i < r; i++){
    if(i < m){
      mxLeft = max(mxLeft, list[i]);
      mnLeft = min(mnLeft, list[i]);
    }
    else{
      mxRight = max(mxRight, list[i]);
      mnRight = min(mnRight, list[i]);
    }
  }
  if(mxLeft < mnRight){ //nic nie robimy
    ll left = helper(l, m, list);
    ll right = helper(m, r, list);
    if(left == -1 || right == -1) return -1;
    return left+right;
  }
  if(mnLeft > mxRight){ //switch
    ll left = helper(l, m, list);
    ll right = helper(m, r, list);
    if(left == -1 || right == -1) return -1;
    return 1 + left+right;
  }
  else{
    // cout << "nie ma wyniku: " <<l << " " << r << " " << mnLeft << " " << mxLeft << " " << mnRight << " " << mxRight << endl;
    return -1; // nie da sie
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  cout << helper(0,n,list) << endl;
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