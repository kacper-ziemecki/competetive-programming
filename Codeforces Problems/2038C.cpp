#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n),b(n),suffix(n, 0), res(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  suffix[n-1] = a[n-1]/b[n-1];
  for(ll i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + a[i]/b[i];
  for(ll i = 0; i < n; i++){
    ll tmp = max(0ll, k-(i+1 == n ? 0 : suffix[i+1]));
    if(tmp*b[i] > a[i]) res[i]=0;
    else res[i] = max(0ll, k-(i+1 == n ? 0 : suffix[i+1]));
    k -= res[i];
  }
  for(auto el : res) cout << el << " ";
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

  solve();
}