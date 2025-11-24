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

string s,t;
const ll maxN = 3e3+1;
ll dp[maxN][maxN];
pair<ll,ll> parent[maxN][maxN];

ll dynamic(ll i, ll j){
  if(i == 0 || j == 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  ll up = dynamic(i-1,j);
  ll left = dynamic(i,j-1);
  ll cross = (s[i-1] == t[j-1] ? 1 : 0) + dynamic(i-1,j-1);
  dp[i][j] = max({up,left,cross});
  if(up == dp[i][j]){
    parent[i][j] = {i-1,j};
  } else if(left == dp[i][j]){
    parent[i][j] = {i,j-1};
  } else{
    parent[i][j] = {i-1,j-1};
  }
  return dp[i][j];
}

void solve()
{
  cin >> s >> t;

  for(ll i = 0; i < maxN; i++){
    for(ll j = 0; j < maxN; j++) dp[i][j] = -1;
  }
  dynamic(s.size(), t.size());
  string res;
  ll i=s.size(), j = t.size();
  while(i > 0 && j > 0){
    if(s[i-1] == t[j-1] && parent[i][j].first == i-1 && parent[i][j].second == j-1){
      res += s[i-1];
    }
    pair<ll,ll> tmp = parent[i][j];
    i = tmp.first; j = tmp.second;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}