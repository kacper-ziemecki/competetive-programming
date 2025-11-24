#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,a,res=0;
string tmp;
const int maxN = 3e3+1;
bitset<maxN> dp[maxN];

void solve()
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    for(int j = 0; j < n; j++){
      dp[i][j] = (tmp[j] == '1' ? 1 : 0);
    }
  }
  // for(int i = 0; i < n; i++) dbg(dp[i]);
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(!dp[i][j]) continue;
      res += ((dp[i] & dp[j]) >> (j+1)).count();
    }
  }
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

}