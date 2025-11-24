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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  for(auto el : list) cout << el << " ";
  cout << endl;
  map<ll,ll> idx;
  set<ll> st;
  for(ll i = 0; i < n; i++){
    auto it = st.upper_bound(list[i]);
    dbg(*it);
    st.emplace(list[i]);
    idx[list[i]] = i;
  }

  ll m, k;
  cin >> m >> k;
  string s, t;
  cin >> s >> t;
  vector<ll> z_function(m, 0);
  for(ll i = 1; i < m; i++){
    ll j = z_function[i-1];
    while(j > 0 && s[j] != s[i]) j = z_function[j-1];
    if(s[i] == s[j]) j++;
    z_function[i] = j;
  }
  for(auto el : z_function) cout << el << " ";
  cout << endl;
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