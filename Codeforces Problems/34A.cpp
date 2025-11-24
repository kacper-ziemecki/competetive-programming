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
  ll n, res = LLONG_MAX;
  cin >> n;
  vector<ll> l(n, 0ll);
  pair<ll, ll> ans;
  for(auto &el : l) cin >> el;
  for(ll i = 0; i < n; i++){
    if(res > abs(l[i] - (i == 0 ? l[n-1] : l[i-1]))){
      ans = {(i == 0 ? n-1 : i-1), i};
      res = abs(l[i] - (i == 0 ? l[n-1] : l[i-1]));
    }
    if(res > abs(l[i] - (i == n-1 ? l[0] : l[i+1]))){
      ans = {(i == n-1 ? 0 : i+1), i};
      res = abs( l[i] - (i == n-1 ? l[0] : l[i+1]));
    }
  }
  cout << ans.first+1 << " " << ans.second+1 << endl;
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