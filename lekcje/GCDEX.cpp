#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> suma, pref;

ll compute(ll n){
  cout << "-----------------------\n";
  dbg(n);
  ll res = 0;
  for(ll i = 1; i*i <= n; i++){
    if(n % i == 0){
      dbg(i, (n/i-1)*i - (n/i-1)*suma[i]);
      res += (n/i-1)*i - (n/i-1)*suma[i];
      if(i != n/i && i != 1){
        dbg(n/i, (n/(n/i)-1)*(n/i) - (n/(n/i)-1)*suma[n/i]);
        res += (n/(n/i)-1)*(n/i) - (n/(n/i)-1)*suma[n/i];
      }
    }
  }
  return res;
}

ll sumaDzielnikow(ll n){
  ll mx = 0;
  for(ll i = 1; i*i <= n; i++){
    if(n % i == 0){
      mx = max(mx,i);
      if(i != n/i && i != 1) mx = max(mx,n/i);
    }
  }
  return mx;
}

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  pref.assign(101,0); suma.assign(101,0);
  for(ll i = 2; i < suma.size(); i++) suma[i] = sumaDzielnikow(i);
  for(ll i = 1; i < pref.size(); i++) pref[i] = pref[i-1] + compute(i); 
  vector<ll> test(101,0), pref1(101,0);
  for(ll i = 1; i < 101; i++){
    for(ll j = i+1; j < 101; j++) test[j] += __gcd(i,j);
  }
  for(ll i = 1; i < 101; i++) pref1[i] = pref1[i-1] + test[i];
  for(ll i = 0; i < 100; i++) dbg(i, pref[i], suma[i], pref1[i]);

  // ll n;
  // while(cin >> n, n != 0) solve(n);
}