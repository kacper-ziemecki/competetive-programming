#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll binpow(ll a, ll b, ll m){
  ll res = 1;
  while(b){
    if(b&1) res *= a;
    a *= a;
    b >>= 1;
    res %= m;
    a %= m;
  }
  return res;
}

void solve(string s)
{
  ll n = s.size();
  vector<ll> prefix_hash(n), suffix_hash(n);
  ll p = 31, power = 1, mod = 100000007;
  for(ll i = 0; i < n; i++){
    power *= p;
    power %= mod;
    prefix_hash[i] = s[i] * power + (i ? prefix_hash[i-1] : 0);
    suffix_hash[n-i-1] = s[n-i-1] * power + (i ? suffix_hash[n-i] : 0);
    prefix_hash[i] %= mod;
    suffix_hash[n-i-1] %= mod;
  }
  // for(auto el : prefix_hash) cout << el << " ";
  // cout << endl;
  // for(auto el : suffix_hash) cout << el << " ";
  // cout << endl;
  ll res = n-1;
  for(ll i = (n+1)/2; i < n; i++){
    // dbg((i-1)-(n-i), i-1);
    // dbg((i-1-(n-i) < 0 ? 1 : (binpow(p, i-1-(n-i), mod) * binpow(binpow(p, i-1-(n-i), mod), mod-2, mod)) % mod));
    ll prefix_h1 = ((prefix_hash[i-1] - (i-1-(n-i) != -1 ? prefix_hash[i-1-(n-i)] : 0)) % mod + mod) % mod;
    prefix_h1 = ((prefix_h1 * (i-1-(n-i) < 0 ? 1 : binpow(binpow(p, i-1-(n-i)+1, mod), mod-2, mod))) % mod + mod) % mod;
    // dbg(prefix_h1);
    ll prefix_h2=-1;
    if(i-1 >= (n-i)){
      // dbg((i-2)-(n-i), i-2);
      prefix_h2 = ((prefix_hash[i-2] - (i-2-(n-i) != -1 ? prefix_hash[i-2-(n-i)] : 0)) % mod + mod) % mod;
      prefix_h2 = ((prefix_h2 * (i-2-(n-i) < 0 ? 1 : binpow(binpow(p, i-2-(n-i)+1, mod), mod-2, mod))) % mod + mod) % mod;
      // dbg(prefix_h2);
    }
    // dbg(prefix_h1, prefix_h2);
    if(prefix_h1 == suffix_hash[i]){
      // cout << "znaleziono z h1\n";
      res = min(res, i-1-(n-i)+1);
    }
    if(prefix_h2 == suffix_hash[i]){
      // cout << "znaleziono z h2\n";
      res = min(res, i-2-(n-i)+1);
    }
  }
  string temp = s.substr(0, res);
  reverse(temp.begin(), temp.end());
  cout << s+temp << endl;
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

  string s;
  while(cin>>s){
    solve(s);
    if(cin.eof()) break;
  }
}