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
  ll n;
  cin >> n;
  vector<vector<ll>> l(n, vector<ll>(3, 0ll));
  for(auto &sub : l){
    for(auto &el : sub) cin >> el;
  }
  vector<pair<ll, ll>> tmp;
  for(auto el : l){
    tmp.emplace_back(el[0], el[2]);
    tmp.emplace_back(el[1], -(el[2]));
  }
  sort(tmp.begin(), tmp.end());
  ll res = 0;
  ll cur = 0;
  for(auto el : tmp){
      cur += el.second;
      res = max(res, cur);
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);
  
#endif

  solve();
}