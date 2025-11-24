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
  ll a = 1, b = 1, c = 1;
  for(ll i = 2; i*i <= n && n > 1; i++){
    while(n%i == 0){
      if(a==1) a *= i;
      else if(b <= a) b *= i;
      else break;
      n /= i;
    }
  }
  c = n;
  if(a==b||a==c||b==c||a==1||b==1||c==1) cout << "NO\n";
  else{
    cout << "YES\n";
    cout << a << " " << b << " " << c << endl;
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