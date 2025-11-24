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
const ll maxN = 1e5+1;
ll lista[maxN][3], dp[maxN][3];

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < 3; j++){
      cin >> lista[i][j];
    }
  }for(ll i = 0; i < n; i++){
    for(ll j = 0; j < 3; j++){
      if(i == 0){
        dp[i][j] = lista[i][j];
      } else{
        dp[i][j] = lista[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
      }
    }
  }  
  cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}