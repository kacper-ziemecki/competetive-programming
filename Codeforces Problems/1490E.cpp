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
  vector<pair<ll,ll>> list(n);
  vector<ll> prefix_sums(n);
  for(auto &el : list) cin >> el.first;
  for(ll i = 0; i < n; i++) list[i].second=i;
  sort(list.begin(), list.end());
  prefix_sums[0] = list[0].first;
  for(ll i=1; i < n; i++) prefix_sums[i]=prefix_sums[i-1]+list[i].first;
  vector<ll> ans{list.back().second+1};
  for(ll i = n-2; i >= 0; i--){
    if(prefix_sums[i] < list[i+1].first) break;
    ans.push_back(list[i].second+1);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto el : ans) cout << el << " ";
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

  ll t;
  cin >> t;
  while(t--)
  solve();  
  
} 