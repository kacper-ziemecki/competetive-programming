#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll dfs(ll i, vector<pair<ll, ll>> &list, vector<bool> &vis, ll dist, pair<ll, ll> &last){
  vis[i] = true;
  bool flag = true;

  ll cnt = 0;
  for(auto el : vis) if(!el) cnt++;

  for(ll j = 0; j < list.size(); j++){
    if(vis[j]) continue;
    ll tmp = dfs(j, list, vis, dist + (abs(list[i].first - list[j].first)+abs(list[i].second-list[j].second)));
    if(flag){
      dist = tmp;
      flag = false;
    } else dist = min(dist, tmp);
  } 
  vis[i] = false;
  return dist;
}

void solve()
{
  ll n,res=LLONG_MAX;
  cin >> n;
  vector<pair<ll, ll>> list(n, {0, 0});
  vector<bool> vis(n, false);
  for(auto &el : list) cin >> el.first >> el.second;
  for(ll i = 0; i < n; i++){
    pair<ll, ll> last;
    res = min(res, dfs(i, list, vis, abs(list[i].first)+abs(list[i].second), last));
    cout << "---\n";
  }
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