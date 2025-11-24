#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll lcm(ll a, ll b){ return (a*b)/__gcd(a,b); }


void solve(){
  ll a,b,c,d,k;
  cin >> a >> b >> c >> d >> k;
  dbg(2*k, lcm(__gcd(a,b), __gcd(c,d)), (2*k)/lcm(__gcd(a,b), __gcd(c,d)));
  cout << 1+2*k/lcm(__gcd(a,b), __gcd(c,d)) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}