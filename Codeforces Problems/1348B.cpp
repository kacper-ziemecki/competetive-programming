#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
void solve(){
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  set<ll> st;
  for(auto el : list) st.emplace(el);
  if(st.size() > k){
    cout << -1 << endl; return;
  }
  for(ll i = 1; i <= n && st.size()<k; i++){
    if(st.count(i)==0) st.emplace(i);
  }
  vector<ll> res;
  for(ll i = 0; i < n; i++){
    for(auto el : st) res.push_back(el);
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el << " ";
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
  
  ll t;
  cin >> t;
  while(t--) solve();
}