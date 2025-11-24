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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(k), t(k), list(n+1, LLONG_MAX);
  for(auto &el : a) cin >> el;
  for(auto &el : t) cin >> el;
  priority_queue<tuple<ll,ll,ll>> pq;
  for(ll i = 0; i < k; i++) pq.push({t[i], a[i], 0});
  while(!pq.empty()){
    tuple<ll,ll,ll> cur = pq.top(); pq.pop();
    if(list[get<1>(cur)] <= get<0>(cur)) continue;
    list[get<1>(cur)] = get<0>(cur);
    if(get<2>(cur) == 0){
      if(get<1>(cur)-1 > 0) pq.emplace(make_tuple(get<0>(cur)+1, get<1>(cur)-1, -1));
      if(get<1>(cur)+1 <= n) pq.emplace(make_tuple(get<0>(cur)+1, get<1>(cur)+1, 1));
    } else if(get<2>(cur) == -1){
      if(get<1>(cur)-1 > 0) pq.emplace(make_tuple(get<0>(cur)+1, get<1>(cur)-1, -1));
    } else {
      if(get<1>(cur)+1 <= n) pq.emplace(make_tuple(get<0>(cur)+1, get<1>(cur)+1, 1));
    }
  }
  for(ll i = 1; i <= n; i++) cout << list[i] << " ";
  cout << endl;
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