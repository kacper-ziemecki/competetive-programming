#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll int
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,p,k;
// const ll maxN = 1e5+1, maxP = 7;
// ll lista1[maxN], lista2[maxN][maxP];
vector<ll> lista1;
vector<vector<ll>> lista2;
// vector<pair<ll,ll>> dp[maxN][1<<maxP];
vector<vector<vector<pair<ll,ll>>>> dp;
// pair<ll,ll> sortedLista1[maxN];
vector<pair<ll,ll>> sortedLista1;

ll calc_sum(vector<pair<ll,ll>> &dpList){
  unordered_map<ll,ll> tmp;
  ll cnt = 0;
  ll sum = 0;
  for(auto el : dpList){
    sum += lista2[el.first][el.second];
    tmp[el.first] = el.second;
  }
  for(ll i = 0; cnt < k; i++){
    if(!tmp.count(sortedLista1[i].second)){
      // cout << "not in dp"; dbg(sortedLista1[i].first);
      sum += sortedLista1[i].first;
      cnt++;
    }
  }
  return sum;
}
void solve()
{
  cin >> n >> p >> k;
  lista1.resize(n);
  lista2.resize(n, vector<ll>(p));
  sortedLista1.resize(n);
  dp.resize(n, vector<vector<pair<ll,ll>>>(1<<p));
  for(ll i = 0; i < n; i++){
    cin >> lista1[i];
    sortedLista1[i] = {lista1[i], i};
  }

  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < p; j++){
      cin >> lista2[i][j];
    }
  }

  sort(sortedLista1.begin(), sortedLista1.end(), greater<>());
  // for(ll i = 0; i < n; i++) dbg(sortedLista1[i].first, sortedLista1[i].second);
  for(ll i = 0; i < p; i++){
    ll mask = (1<<i);
    // dbg(calc_sum(tmp));
    dp[0][mask] = {{0,i}};
  }
  for(ll i = 1; i < n; i++){
    for(ll mask = 0; mask < (1<<p); mask++){
      dp[i][mask] = dp[i-1][mask];
      for(ll j = 0; j < p; j++){
        if(mask & (1<<j)){
          vector<pair<ll,ll>> tmp = dp[i-1][mask^(1<<j)];
          tmp.pb({i, j});
          ll prevSum = calc_sum(tmp);
          ll curSum = calc_sum(dp[i][mask]);
          if(prevSum > curSum) dp[i][mask] = tmp;
        }
      }
    }
  }
  cout << calc_sum(dp[n-1][(1<<p)-1]) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

 
}