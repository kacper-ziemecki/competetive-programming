#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h, ll i, ll x, ll mid){
  g *= mid; h *= mid; i *= mid;
  x -= max(0ll, (g-a)*d);
  x -= max(0ll, (h-b)*e);
  x -= max(0ll, (i-c)*f);
  return x >= 0;
}

void solve()
{
  string s;
  ll a,b,c,d,e,f,x,g=0,h=0,i=0;
  cin >> s >> a >> b >> c >> d >> e >> f >> x;
  for(auto el : s){
    if(el == 'B') g++;
    else if(el == 'S') h++;
    else i++;
  }
  ll l=0, r=1e13;
  while(l<r){
    ll mid = (l+r+1)/2;
    if(check(a,b,c,d,e,f,g,h,i,x,mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
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