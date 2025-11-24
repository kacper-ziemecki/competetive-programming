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
  ll n,m;
  cin >> n >> m;
  vector<pair<ll, ll>> a(n, {0, 0}), b(m, {0, 0});
  for(auto &el : a) cin >> el.first >> el.second;
  for(auto &el : b) cin >> el.first >> el.second;
  vector<ll> one(100, 0ll), two(100, 0ll);
  ll last = 0;
  for(auto el : a){
    for(ll i = last; i < last+el.first; i++){
        one[i] = min(100ll, el.second);
    }
    last += el.first;
  }
  last = 0;
  for(auto el : b){
    for(ll i = last; i < last+el.first; i++){
      two[i] = min(100ll, el.second);
    }
    last += el.first;
  }
  ll res = 0;
  for(ll i = 0; i < 100; i++){
    // cout << one[i] << " " << two[i] << endl;
    res = max(res, two[i] - one[i]);
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  
#endif

  solve();
}