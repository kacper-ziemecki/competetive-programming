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

ll n,m,u,v;
const ll maxN = 19;
ll matrix[maxN][maxN];
ll dp[1<<maxN];

string to_bits(ll n){
  string s;
  for(ll i = 0; i < maxN; i++){
    s += (n&(1<<i) ? '1' : '0');
  }
  return s;
}

void solve()
{
  cin >> n >> m;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    matrix[u][v] = 1;
    matrix[v][u] = 1;
  }
  for(ll mask = 0; mask < (1<<n); mask++){
    bool flag = true;
    for(ll u = 1; u <= n; u++){
      if((mask & (1<<(u-1))) == 0) continue;
      for(ll v = 1; v <= n; v++){
        if(((mask & (1<<(v-1))) == 0) || (u == v)) continue;
        // dbg(u,v, matrix[u][v]);
        if(matrix[u][v] == 0) flag = false;
      }
    }
    // dbg(to_bits(mask), flag);
    dp[mask] = (flag ? 1 : __builtin_popcount(mask));
  }
  for(ll mask = 0; mask < (1<<n); mask++){
    for(ll submask = mask; submask != 0; submask = (submask-1) & mask){
      ll subset = mask ^ submask;
      dp[mask] = min(dp[mask], dp[submask]+dp[subset]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

 
}