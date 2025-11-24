#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll a,b,n;
  cin >> a >> b;
  n = a+b;
  if(a > b){
    for(ll i = 0; i < n; i++){
      if(!(i&1) && a>0){
        a--;
        cout << '0';
      } else if(b > 0){
        b--;
        cout << '1';
      } else{
        a--;
        cout << '0';
      }
    }
  } else{
    for(ll i = 0; i < n; i++){
      if(!(i&1) && b>0){
        b--;
        cout << '1';
      } else if(a>0){
        a--;
        cout << '0';
      } else{
        b--;
        cout << '1';
      }
    }
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