#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool tPrime(ll a, vector<bool>& primes){
  if(a == 1) return false;
  if((ll)sqrt(a)*(ll)sqrt(a) != a) return false;
  if(!primes[(ll)sqrt(a)]) return false;
  return true;
}

void solve(){
  vector<bool> primes(1000001, true);
  primes[0] = primes[1] = false;
  for(ll i = 2; i < primes.size(); i++){
    if(primes[i]){
      for(ll j = i*i; j < primes.size(); j+=i) primes[j]=false;
    }
  }
  ll n;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  for(auto el : list){
    if(tPrime(el, primes)) cout << "YES\n";
    else cout << "NO\n";
  }
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