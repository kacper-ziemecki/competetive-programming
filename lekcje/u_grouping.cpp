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


ll n;
const ll maxN = 16;
ll lista[maxN][maxN], dp[(1<<maxN)];

string to_bits(ll n){
  string s;
  for(ll i = 0; i < maxN; i++){
    s += (n&(1<<i) ? '1' : '0');
  }
  return s;
}

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      cin >> lista[i][j];
    }
  }
  for(ll mask = 0; mask < (1<<n); mask++) dp[mask] = 0;

  for(ll mask = 0; mask < (1<<n); mask++){
    // dbg(to_bits(mask));
    for(ll i = 0; i < n; i++){
      if((mask & (1<<i)) == 0) continue;
      for(ll j = 0; j < i; j++){
        if((mask & (1<<j)) == 0) continue;
        // dbg(to_bits(1<<i), to_bits(1<<j), to_bits(mask & (1<<i)),i,j);
        dp[mask] += lista[i][j];
      }
    }
  }
  // dbg(dp[1], dp[2]);
  for(ll mask = 0; mask < (1<<n); mask++){
    for(ll submask = mask; submask != 0; submask = (submask-1)&mask){
      ll subset = mask ^ submask;
      dp[mask] = max(dp[mask], dp[subset] + dp[submask]);
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