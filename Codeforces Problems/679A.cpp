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


bool is_prime(ll x){
  for(ll i = 2; i*i <= x; i++) if(x%i==0) return false;
  return true;
}

void solve()
{
  vector<ll> primes;
  for(ll i = 2; primes.size() < 19; i++){
    if(is_prime(i)){
      primes.push_back(i);
      if(i*i < 100) primes.push_back(i*i);
    }
  }
  ll cnt=0;
  string ans;
  for(auto el : primes){
    cout << el << endl;
    cin >> ans;
    if(ans == "yes") cnt++;
  }
  if(cnt >= 2){
    cout << "composite" << endl;
  } else{
    cout << "prime" << endl;
  }
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}