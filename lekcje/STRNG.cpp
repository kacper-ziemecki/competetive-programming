#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n;
  cin >> n;
  vector<ll> list(n),pref(n),suf(n);
  for(auto &el : list) cin >> el;
  pref[0] = list[0]; suf[n-1] = list[n-1];
  for(ll i = 1; i < n; i++){
    pref[i] = __gcd(pref[i-1], list[i]);
    suf[n-i-1] = __gcd(suf[n-i], list[n-i-1]);
  }
  ll cnt=0;
  for(ll i = 0; i < n; i++){
    ll left = (i ? pref[i-1] : suf[i+1]), right = (n-i-1 ? suf[i+1] : pref[i-1]);
    // dbg(i, n-i-1, left, right);
    cnt += (__gcd(left,right) != 1);
  }
  cout << cnt << endl;
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