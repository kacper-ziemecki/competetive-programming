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
  ll n,m,l,power=0;
  cin >> n >> m >> l;
  vector<pair<ll,ll>> hurdles(n), powers(m);
  vector<vector<pair<ll,ll>>> powers1;
  for(auto &el : hurdles) cin >> el.first >> el.second;
  for(auto &el : powers) cin >> el.first >> el.second;
  ll j = 0;
  powers1.push_back({});
  for(ll i = 0; i < m; i++){
    while(j < n && powers[i].first >= hurdles[j].first){
      j++;
      powers1.push_back({});
    }
    powers1.back().push_back(powers[i]);
  }
  for(auto sub : powers1){
    for(auto el : sub) cout << el.first << "," << el.second << endl;
    cout << endl;
  }
  cout << "------\n";
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