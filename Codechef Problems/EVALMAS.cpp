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
  if(x > 0 && n+1 >= x){
    for(ll i = 0; i < n+1-abs(x); i++){
      cout << '*';
    }
    for(ll i = 0; i < abs(x)-1; i++){
      if(x <= 0) cout << '-';
      else cout << '+';
    }
  } else if(x <= 0 && n > abs(x)){
    for(ll i = 0; i < n+1-abs(x)-2; i++){
      cout << '*';
    }
    for(ll i = 0; i < abs(x)+1; i++){
      if(x <= 0) cout << '-';
      else cout << '+';
    }
  } else{
    cout << -1;
  }
  cout << endl;
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