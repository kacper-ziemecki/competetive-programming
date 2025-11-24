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
  ll n,m,k;
  cin >> n;
  vector<ll> a(n);
  for(auto &el : a) cin >> el;
  cin >> m;
  vector<ll> b(m);
  for(auto &el : b) cin >> el;
  cin >> k;
  vector<ll> c;
  if(k) c.assign(k, 0);
  for(auto &el : c) cin >> el;

  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  vector<vector<pair<ll,ll>>> p(n+1, vector<pair<ll,ll>>(m+1, {0, 0}));
  
  for(ll i = 1; i <= n; i++){
    for(ll j = 1; j <= m; j++){
      ll mx = max({dp[i-1][j], dp[i][j-1], (a[i-1]==b[j-1] ? dp[i-1][j-1]+1 : dp[i-1][j-1])});
      if(mx == dp[i-1][j]){
        p[i][j] = {i-1, j};
      } else if(mx == dp[i][j-1]){
        p[i][j] = {i, j-1};
      } else{
        p[i][j] = {i-1, j-1};
      }
      dp[i][j] = mx;
    }
  }
  pair<ll,ll> cur = {n, m};
  vector<ll> res;
  while(cur.first != 0 || cur.second != 0){
    if(cur.first - p[cur.first][cur.second].first == 1 && cur.second - p[cur.first][cur.second].second == 1 && a[cur.first-1] == b[cur.second-1]) res.pb(a[cur.first-1]);
    cur = p[cur.first][cur.second];
  }
  reverse(res.begin(), res.end());

  map<ll, vector<ll>> idx;
  for(ll i = 0; i < res.size(); i++) idx[res[i]].pb(i);

  if(!k){ cout << res.size() << endl; return; }
  ll ans = -1;
  for(auto el : idx[c[0]]){
    ll j = el;
    bool flag = true;
    for(ll i = 1; i < k; i++){
      if(!idx.count(c[i])){flag = false; break; }
      // dbg(el, c[0], c[i]);
      // for(auto el : idx[c[i]]) cout << el << " ";
      // cout << endl;
      ll indeks = upper_bound(idx[c[i]].begin(), idx[c[i]].end(), j) - idx[c[i]].begin();
      if(indeks == idx[c[i]].size()){ flag = false; break; }
      j = idx[c[i]][indeks];
      // dbg(j);
    }
    if(flag){
      // dbg(el, j, k, res.size());
      // for(auto el : res) cout << el << " ";
      // cout << endl;
      ans = max(ans, el+k+(ll)(res.size()-j-1));
    }
  }
  cout << ans << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}