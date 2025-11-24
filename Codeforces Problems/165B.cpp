#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll iter = 0;

bool check(ll m, ll n, ll k){
  ll power = 1, suma = 0;
  while(power <= m){
    suma += m/power;
    power *= k;
  }
  // dbg(suma, n);
  return suma >= n;
}

void solve()
{
  ll n,k;
  cin >> n >> k;
  ll l = 1, r = 1e9;

  while(l < r){
    if(iter++ > 100) return;
    ll m = (l+r)/2;
    // dbg(l,m,r);
    if(check(m, n, k)) r = m;
    else l = m+1;
  }
  cout << r << endl;
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
  
  solve(); 
}