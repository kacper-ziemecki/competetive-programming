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
const ll maxN = 3e3+1;
ll lista[maxN];
ll dp[maxN][maxN][2];

ll dynamic(ll left, ll right, bool flag){
  if(left==right){
    return dp[left][right][flag]=(flag ? lista[left] : 0);
  }
  if(dp[left][right][flag] != -1){
    return dp[left][right][flag];
  }
  if(flag){
    dp[left][right][flag] = max(lista[left]+dynamic(left+1,right,!flag), lista[right]+dynamic(left,right-1,!flag));
  } else{
    ll lewo = lista[left]+dynamic(left+1,right,flag);
    ll prawo = lista[right]+dynamic(left,right-1,flag);
    ll choice = dynamic(left,right,!flag);
    if(choice == lewo){
      dp[left][right][flag] = dynamic(left+1,right,!flag);
    } else{
      dp[left][right][flag] = dynamic(left,right-1,!flag);
    }
  }
  return dp[left][right][flag];
}

void solve()
{
  cin >> n;
  ll suma=0;
  for(ll i = 0; i < n; i++){
    cin >> lista[i];
    suma += lista[i];
  }

  for(ll i = 0; i <= n; i++){
    for(ll j = 0; j <= n; j++){
      for(ll k = 0; k < 2; k++){
        dp[i][j][k] = -1;
      }
    }
  }
  dynamic(0, n-1, true);
  // for(ll i = 0; i <= n; i++){
  //   for(ll j = 0; j <= n; j++){
  //     for(ll k = 0; k < 2; k++){
  //       cout << dp[i][j][k] << ",";
  //     }
  //     cout << " | ";
  //   }
  //   cout << endl;
  // }
  cout << dp[0][n-1][true] - (suma - dp[0][n-1][true]) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}