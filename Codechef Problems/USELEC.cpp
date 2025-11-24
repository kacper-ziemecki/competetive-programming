#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,x;
  cin >> n >> x;
  vector<ll> one(n), two(n), three(n);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  for(ll i = 0; i < n; i++){
    three[i] = one[i]-two[i];
  }
  sort(three.begin(), three.end(), greater<>());
  ll a=0, b=0;
  for(auto el : three){
    if(el <= 0){
      ll tmp = min(1-el, x);
      x -= tmp;
      el += tmp;
    }
    if(el > 0) a++;
    if(el < 0) b++;
  }
  if(a > n/2) cout << "YES\n";
  else cout << "NO\n";
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


  ll t;
  cin >> t;
  while(t--) solve();
  
  
}