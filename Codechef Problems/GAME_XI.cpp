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
  ll n,m;
  cin >> n >> m;
  vector<ll> a(n), b(m), c;
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  if(n < 4 || m < 4 || n+m < 11){
    cout << -1 << endl; return;
  }
  sort(a.begin(), a.end(), greater<>());
  sort(b.begin(), b.end(), greater<>());
  ll res = a[0]+a[1]+a[2]+a[3]+b[0]+b[1]+b[2]+b[3];
  for(ll i = 4; i < n; i++) c.push_back(a[i]);
  for(ll i = 4; i < m; i++) c.push_back(b[i]);
  sort(c.begin(), c.end(), greater<>());
  for(ll i = 0; i < 3; i++) res += c[i];
  cout << res << endl;
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