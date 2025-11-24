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
  ll n,a=0,b=0;
  cin >> n;
  while(!(n&1)){
    a++; n>>=1;
  }
  if(n!=1) b++;
  for(ll i = 3; i*i <= n; i+=2){
    if(n%i==0) b+=2;
  }
  if(a == 1 && b == 0) cout << "Ashishgup" << endl;
  else if(b==0) cout << "FastestFinger" << endl;
  else if(a == 0 && b > 0) cout << "Ashishgup" << endl;
  else if(a > 1 && b > 0) cout << "Ashishgup" << endl;
  else if(a == 1 && b == 1) cout << "FastestFinger" << endl;
  else if(a == 1 && b > 1) cout << "Ashishgup" << endl;
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