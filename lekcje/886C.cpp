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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  map<ll,ll> node_to_idx, idx_to_node;
  ll cnt=1;
  node_to_idx[1] = 0;
  idx_to_node[0] = 1;
  for(ll i = 1; i <= n; i++){
    if(idx_to_node.count(list[i-1])){
      idx_to_node[i] = idx_to_node[list[i-1]];
      idx_to_node.erase(list[i-1]);
      node_to_idx[idx_to_node[i]] = i;
    } else{
      idx_to_node[i] = ++cnt;
      node_to_idx[cnt] = i;
    }
  }
  cout << cnt << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}