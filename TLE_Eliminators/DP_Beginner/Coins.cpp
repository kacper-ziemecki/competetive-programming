#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
const int maxn = 3002;
double lista[maxn];
double dp[maxn][maxn];

void solve()
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> lista[i];
  }
  dp[0][0] = 1-lista[0];
  dp[0][1] = lista[0];
  for(int id = 1; id < n; id++){
    for(int selected = 0; selected <= id+1; selected++){
      dp[id][selected] = dp[id-1][selected] * (1 - lista[id]);
      if(selected > 0) dp[id][selected] += dp[id-1][selected-1]*lista[id];
    }
  }
  double res = 0;
  for(int i = n/2+1; i <= n; i++){
    res += dp[n-1][i];
  }
  cout << fixed << setprecision(10) << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();

}