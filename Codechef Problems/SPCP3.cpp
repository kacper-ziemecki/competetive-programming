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
  ll a,b,res=LLONG_MAX;
  cin >> a >> b;
  for(ll i = 1; i*i <= a+b; i++){
    if((a+b)%i == 0){
      res = min(res, abs(a-i*((a+b)/i-1)) + abs(b-i));
      if(i > 1){
        res = min(res, abs(a-(i-1)*((a+b)/i)) + abs(b-(a+b)/i));
      }
    }
  }
  cout << res/2 << endl;
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