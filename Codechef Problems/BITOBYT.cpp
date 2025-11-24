#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll binpow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b&1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}


void solve(){
  ll n;
  cin >> n;
  ll cnt = binpow(2, (n-1)/26);
  if(n%26 == 1 || n%26 == 2){
    cout << cnt << " " << 0 << " " << 0 << endl;
  } 
  else if(n%26 >= 3 && n%26 <= 10){
    cout << 0 << " " << cnt << " " << 0 << endl;
  } else{
    cout << 0 << " " << 0 << " " << cnt << endl;
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}