#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll MOD = 1e9+7;
map<ll,ll> fact,inv_fact;

ll binpow(ll a, ll b){
  ll res = 1;
  while(b){
    if(b&1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll factorial(ll x){
  ll res = 1;
  for(ll i = 2; i <= x; i++) res = (res * i) % MOD;
  return res;
}


ll combination(ll n, ll r){
  if(!fact.count(n)) fact[n] = factorial(n);
  if(!inv_fact.count(r)) inv_fact[r] = binpow(factorial(r), MOD-2);
  if(!inv_fact.count(n-r)) inv_fact[n-r] = binpow(factorial(n-r), MOD-2);
  return (((fact[n] * inv_fact[r]) % MOD) * inv_fact[n-r]) % MOD;
}
void solve()
{
  ll n;
  cin >> n;
  ll res = 0;
  // for(ll r = 0; r < n; r++) res = (res + combination(n-1,r)) % MOD;
  cout << (factorial(n) - binpow(2, n-1) + MOD) % MOD << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}