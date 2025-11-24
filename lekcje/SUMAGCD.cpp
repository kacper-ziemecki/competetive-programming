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
  ll n,oldN,a,res=0;
  cin >> n;
  set<ll> st;
  for(ll i = 0; i < n; i++){
    cin >> a;
    st.emplace(a);
  }
  oldN = n;
  n = st.size();
  vector<ll> list, pref(st.size()), suf(st.size());
  for(auto el : st) list.pb(el);
  if(n == 1 && oldN > 1){
    cout << 2*list[0] << endl; return;
  }
  pref[0] = list[0];
  suf[n-1] = list[n-1];
  for(ll i = 1; i < n; i++){
    pref[i] = __gcd(pref[i-1],list[i]);
    suf[n-i-1] = __gcd(suf[n-i], list[n-i-1]);
  }
  for(ll i = 0; i < n; i++){
    res = max(res, list[i] + __gcd(i ? pref[i-1] : 0, n-i-1 ? suf[i+1] : 0));
  }
  cout << res << endl;
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