#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const hs primes[2] = {5586985605742039601,6889537187409766193};
int n;
const int maxn = 2e5+1;
int lista[maxn], res[maxn];
hs hash_pre[2][maxn], hash_suf[2][maxn], prime_powers[2][maxn];

pair<hs,hs> get_pref(int l, int r){
  pair<hs,hs> res = {hash_pref[0][r], hash_pref[1][r]};
  if(l-1 < 0) return res;
  res.first -= hash_pref[0][l-1]*prime_powers[0][r-l+1];
  res.second -= hash_pref[1][l-1]*prime_powers[0][r-l+1];
  return res;
}

pair<hs,hs> get_suf(int l, int r){
  pair<hs,hs> res = {hash_suf[0][l], hash_suf[1][l]};
  if(r+1 >= n) return res;
  res.first -= hash_suf[0][r+1]*prime_powers[0][r-l+1];
  res.second -= hash_suf[1][r+1]*prime_powers[0][r-l+1];
  return res;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];

  prime_powers[0][0] = prime_powers[1][0] = 1;
  for(int i = 1; i <= n; i++){
    prime_powers[0][i] = prime_powers[0][i-1] * primes[0];
    prime_powers[1][i] = prime_powers[1][i-1] * primes[1];
  }

  hash_pref[0] = lista[0];
  hash_pref[n-1] = lista[n-1];

  for(int i = 1; i < n; i++){
    hash_pref[i] = hash_pref[i-1]*primes[0] + lista[i];
    hash_suf[n-i-1] = hash_suf[n-i]*primes[1] + lista[n-i-1];
  }

  for(int dlugosc = 1; dlugosc <= n; dlugosc++){
    for(int poczotek = 0; poczotek+dlugosc-1 < n; poczotek+=dlugosc){
      
    }
  }
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