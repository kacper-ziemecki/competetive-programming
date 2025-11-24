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
  ll n,zeros=0,ones=0,a;
  cin >> n;
  for(ll i = 0; i < n; i++){
    cin >> a;
    if(a == 0) zeros++;
    else ones++;
  }
  for(ll i = 0; ones > 0 && zeros > 0; i++){
    if(i&1){
      ones--;
    }else{
      zeros--;
    }
  }
  if(ones == 0) cout << 0 << endl;
  else cout << 1 << endl;
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