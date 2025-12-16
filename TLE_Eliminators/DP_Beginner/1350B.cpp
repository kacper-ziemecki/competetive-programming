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

const int maxn = 1e5+1;
vector<int> divs[maxn];
map<int,int> last;

void solve()
{
  int n;
  cin >> n;
  vector<int> lista(n), dp(n);
  for(auto &el : lista) cin >> el;
  dp[0] = 1;
  last[lista[0]] = 0;
  for(int i = 1; i < n; i++){
    dp[i] = 1;
    for(int divisor : divs[i+1]){
      // dbg(i+1, divisor);
      if(lista[divisor-1] >= lista[i]) continue;
      dp[i] = max(dp[i],dp[divisor-1]+1);
    }
    last[lista[i]] = i;
    // dbg(lista[i], last[lista[i]]);
  }
  int res = 0;
  for(auto el : dp){
    // cout << el << ' ';
    res = max(res, el);
  }
  // cout << endl;
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif


  for(int i = 2; i < maxn; i++){
    for(int j = 1; j*j <= i; j++){
      if(i % j == 0){
        divs[i].pb(j);
        if(j != i/j && i/j != i) divs[i].pb(i/j);
      }
    }
  }

  int t;
  cin >> t;
  while(t--)
  solve();

}