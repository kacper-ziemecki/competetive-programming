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
  ll n,m,x,y,l;
  cin >> n >> m >> x >> y >> l;
  ll a = ((x+l-1)/l) * ((y+l-1)/l);
  ll b = ((m-y)/l) * ((x+l-1)/l);
  ll c = ((n-x)/l) * ((y+l-1)/l);
  ll d = ((m-y)/l) * ((n-x)/l);
  cout << a+b+c+d << endl;
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