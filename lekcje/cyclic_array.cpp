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

ll n,k,l;
vector<vector<ll>> up;
vector<ll> _next,lista,reverse_lista,prefixSum,reverse_prefixSum;

ll calc_edge(ll i){
  ll cur_sum = prefixSum[i];
  ll sum_to_search = cur_sum + k - lista[i];
  return upper_bound(prefixSum.begin(), prefixSum.end(), sum_to_search) - prefixSum.begin();
}

void solve()
{
  cin >> n >> k;
  l = ceil(log2(n));
  lista.resize(n); prefixSum.resize(n); _next.resize(n); up.assign(n+2, vector<ll>(l+1, n+1));
  reverse_lista.resize(n); reverse_prefixSum.resize(n);
  for(auto &el : lista) cin >> el;
  prefixSum[0] = lista[0];
  for(ll i = 1; i < n; i++) prefixSum[i] = prefixSum[i-1] + lista[i];

  for(ll i = 0; i < n; i++) reverse_lista[n-i-1] = lista[i];
  reverse_prefixSum[0] = reverse_lista[0];
  for(ll i = 1; i < n; i++) reverse_prefixSum[i] = reverse_prefixSum[i-1] + reverse_lista[i];

  // cout << "reverse_lista:\n";
  // for(auto el : reverse_lista) cout << el << " ";
  // cout << endl;
  
  // cout << "reverse_prefixSum:\n";
  // for(auto el : reverse_prefixSum) cout << el << " ";
  // cout << endl;

  for(ll i = 0; i < n; i++){
    ll j = calc_edge(i);
    _next[i] = j;
    // dbg(i, _next[i]);
  }
  for(ll i = n-1; i >= 0; i--){
    up[i][0] = _next[i];
    for(ll j = 1; j <= l; j++) up[i][j] = up[up[i][j-1]][j-1];
  }
  
  // for(ll i = 0; i <= n; i++){
  //   cout << i << " -> ";
  //   for(ll j = 0; j <= l; j++){
  //     cout << up[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  ll res=LLONG_MAX;
  for(ll first = 0; first <= min(n-1, _next[0]); first++){
    ll cur_sum = (first ? prefixSum[first-1] : 0);
    ll sum_to_search = k - cur_sum;
    // dbg(cur_sum, sum_to_search, (upper_bound(reverse_prefixSum.begin(), reverse_prefixSum.end(), sum_to_search) - reverse_prefixSum.begin() - 1));
    ll last = n - 1 - (upper_bound(reverse_prefixSum.begin(), reverse_prefixSum.end(), sum_to_search) - reverse_prefixSum.begin() - 1);
    // dbg(first, last);
    ll tmpRes=1, cur=first;
    for(ll i = l; i >= 0; i--){
      if(up[cur][i] <= last){
        tmpRes += pow(2, i);
        cur = up[cur][i];
      }
    }
    if(cur < last) tmpRes++;
    // dbg(tmpRes);
    res = min(res, tmpRes);
  }
  cout << res << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}