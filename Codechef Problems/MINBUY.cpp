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
  vector<ll> a(n), b(n), c(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(ll i = 0; i < n; i++) c[i] = a[i]*b[i];
  sort(c.begin(), c.end(), greater<>());
  ll sum=0;
  for(ll i = 0; i < n; i++){
    sum += c[i];
    if(sum >= x){
      cout << i+1 << endl;
      return;
    }
  }
  cout << -1 << endl;
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
  while(t--)
  solve();
  
  
}