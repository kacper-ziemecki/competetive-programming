#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll binpow(ll a, ll b, ll mod){
  ll res = 1;
  while(b){
    if(b&1) res *= a;
    a *= a;
    res %= mod;
    a %= mod;
  }
  return res;
}

bool check(vector<ll>& prefix_hash, vector<ll>& suffix_hash, ll m, ll n, ll p, ll mod){
  ll hash = prefix_hash[m-1];
  for(ll i = n-m; i >= 0; i--){
    ll curHash = ((suffix_hash[i]-(i+m == n ? suffix_hash[i+m] : 0)) % mod + mod) % mod;
    curHash = ((curHash * binpow(binpow(p, n-(i+m), mod), mod-2, mod) % mod) % mod + mod) % mod;
    if(hash == curHash) return true;
  }
  return false;
}

void solve()
{
  string s;
  cin >> s;
  ll n = s.size(), p = 31, mod = 100000007;
  vector<ll> prefix_hash(n), suffix_hash(n);
  prefix_hash[0] = (binpow(p, 0, mod) * s[0]) % mod;
  suffix_hash[n-1] = (binpow(p, 0, mod) * s[n-1]) % mod;
  for(ll i = 1; i < n; i++){
    prefix_hash[i] = (prefix_hash[i-1] + (binpow(p, i, mod) * s[i]) % mod) % mod;
    suffix_hash[n-i-1] = (suffix_hash[n-i] + (binpow(p, i, mod) * s[n-i-1]) % mod) % mod;
  }
  ll l=1,r=n;
  while(l > r){
    ll m = l+(r-l+1)/2;
    if(check(prefix_hash,suffix_hash,m,n,p,mod)) l=m;
    else r=m-1;
  }
  cout << l << endl;
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

  ll t;
  cin >> t;
  while(t--) solve();
}