#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll MOD = 1e9+7;

ll binpow(ll a, ll b){
  ll res = 1;
  while(b){
    if(b&1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

void solve(){
  ll a,b,n;
  cin >> a >> b >> n;
  cout << (__gcd(abs(a-b), (binpow(a,n)+binpow(b,n)) % abs(a-b)) % MOD) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}