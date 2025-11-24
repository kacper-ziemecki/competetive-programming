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
  ll n;
  cin >> n;
  vector<ll> wagon(n), miasto(n);
  unordered_map<ll,ll> idx;
  for(auto &el : wagon) cin >> el;
  for(auto &el : miasto) cin >> el;
  for(ll i = 0; i < n; i++) idx[miasto[i]] = i; 

  ll prev = LLONG_MAX, res=0;
  for(ll i = n-1; i >= 0; i--){
    // dbg(idx[wagon[i]], prev, res);
    if(idx[wagon[i]] < prev) res += 1;
    prev = idx[wagon[i]];
  }  
  if(idx[wagon[0]] == 0) res--;
  cout << res << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  solve();
}