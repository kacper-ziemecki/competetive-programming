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


ll calc(map<ll, ll>& mp){
  for(ll i = 0;;i++){
    if(mp[i]<=0){ 
      return i; 
    }
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n);
  map<ll,ll> mp;
  for(auto& el : list) cin >> el;
  for(auto el : list) mp[el]++;
  ll cur = calc(mp);
  cout << cur << endl;
  cin >> cur;
  while(cur != -1 && cur != -2){
    cout << cur << endl;
    cin >> cur;
  }
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  ll t;
  cin >> t;
  while(t--)
  solve();
}