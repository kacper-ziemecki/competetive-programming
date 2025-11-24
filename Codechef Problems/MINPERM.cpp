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
  ll n;
  cin >> n;
  if(n&1){
    for(ll i = 0; i < n-3; i++){
      if(i&1){
        cout << i << " ";
      } else{
        cout << i+2 << " ";
      }
    }
    cout << n-1 << " " << n << " " << n-2;
    cout << endl;
  } else{
    for(ll i = 0; i < n; i++){
      if(i&1){
        cout << i << " ";
      } else{
        cout << i+2 << " ";
      }
    }
    cout << endl;
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