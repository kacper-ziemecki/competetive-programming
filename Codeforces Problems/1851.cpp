#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n, 0ll), b, c;
  for(auto &el : a) cin >> el;
  for(ll i = 0; i < n; i++){
    if(a[i]&1){
      c.push_back(a[i]);
    } else{
      b.push_back(a[i]);
    }
  }
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  ll x=0,y=0;
  for(ll i = 0; i < n; i++){
    if(a[i]&1){
      a[i] = c[x];
      x++;
    } else{
      a[i] = b[y];
      y++;
    }
  }
  for(ll i = 1; i < n; i++){
    if(a[i-1] > a[i]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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