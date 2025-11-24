#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void extended_euclid(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1; y = 0;
    return;
  }
  ll x1,y1;
  extended_euclid(b, a%b, x1, y1);
  x = y1;
  y = x1 - (a/b)*y1;
}

bool linear_diophantine_equation(ll a, ll b, ll c, ll &x, ll &y){
  extended_euclid(abs(a),abs(b),x,y);
  ll g = __gcd(a,b);
  if(c % g) return false;

  x *= (c/g);
  y *= (c/g);
  if(a < 0) x = -x;
  if(b < 0) y = -y;
  return true;
}

void solve(){
  ll n,m,k,x,y;
  cin >> n >> m >> k;
  if(!linear_diophantine_equation(m,k,n,x,y)){ cout << -1 << endl; return; }
  ll step = m/__gcd(m,k);
  if(y >= 0){
    cout << y-step*(y/step) << endl;
  } else{
    cout << y+step*((y+step-1)/step) << endl;
  }
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