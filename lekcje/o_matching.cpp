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

const ll maxn = 21, MOD = 1e9+7;
bool lista[maxn][maxn];
unordered_map<ll,ll> dp1,dp2;

string to_bits(ll n){
  string s;
  for(ll i = 0; i < maxn; i++){
    s += (n&(1<<i) ? '1' : '0');
  }
  return s;
}

void print(unordered_map<ll,ll> dp, string name){
  cout << name << ":\n";
  for(auto [maska, val]: dp){
    cout << to_bits(maska) << " -> " << val << endl;
  }
  cout << endl;
}
void solve()
{
  ll n;
  cin >> n;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      cin >> lista[i][j];
    }
  }
  for(ll i = 0; i < n; i++){
    if(lista[0][i]){
      dp1[1<<i]=1;
    }
  }
  // print(dp1, "dp1");

  for(ll i = 1; i < n; i++){
    for(ll j = 0; j < n; j++){
      for(auto [maska, val] : dp1){
        if((maska & (1 << j)) == 0 && lista[i][j]){
          dp2[maska|(1 << j)] += val;
          dp2[maska|(1 << j)] %= MOD;
        }
      }
    }
    swap(dp1, dp2);
    dp2.clear();
    // print(dp1, "dp1");
  }
  // dbg(to_bits((1<<n)-1));
  cout << dp1[(1<<n)-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

 
}