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

ll n,w,res=0;
const ll maxN= 101, maxW = 1e9+1, maxV = 1e3+1;
pair<ll,ll> lista[maxN];
ll dp[maxN][maxV*maxN];

ll helper(ll id, ll value){
  if(value <= 0) return 0;
  if(id == n) return maxW;
  if(dp[id][value] != -1) return dp[id][value];
  return dp[id][value] = min(helper(id+1,value),lista[id].first+helper(id+1,value-lista[id].second));
}

void set_dp(){
  for(ll id = 0; id < n; id++){
    for(ll value = 0; value < maxV*maxN; value++) dp[id][value]=-1;
  }
}
void solve()
{
  cin >> n >> w;
  for(ll i = 0; i < n; i++) cin >> lista[i].first >> lista[i].second;
  set_dp();
  for(ll value = 0; value < maxV*maxN; value++){
    if(helper(0,value) <= w) res = value;
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