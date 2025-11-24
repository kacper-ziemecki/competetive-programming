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
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  map<ll,ll> mp1, mp2;
  for(ll i = 0; i < n; i++) mp1[a[i]]=i;
  for(ll i = 0; i < n; i++){
    ll shift = (i-mp1[b[i]] < 0 ? n+(i-mp1[b[i]]) : i-mp1[b[i]]);
    c[i] = shift;
    mp2[shift]++;
  }
  ll mx=0;
  for(auto el : mp2) mx = max(mx, el.second);
  cout << mx << endl;
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