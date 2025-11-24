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



void solve()
{
  ll n,suma=0,res=LLONG_MAX;
  cin >> n;
  vector<ll> list(n),pref(n),suf(n);
  for(auto &el : list) cin >> el;
  if(n==1){cout << 1 << endl; return;}
  pref[0] = list[0];
  suf[n-1] = list[n-1];
  suma = list[0];
  for(ll i = 1; i < n; i++){
    suma += list[i];
    pref[i] = __gcd(pref[i-1], list[i]);
    suf[n-i-1] = __gcd(suf[n-i], list[n-i-1]);
  }
  for(ll i = 0; i < n; i++){
    res = min(res, (suma-list[i])/__gcd(i ? pref[i-1] : 0, n-i-1 ? suf[i+1] : 0)+1);
  }
  cout << res << endl;
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