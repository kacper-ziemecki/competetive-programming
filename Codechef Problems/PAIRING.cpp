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
  vector<bool> vis(n, false);
  vector<pair<ll, ll>> list(m);
  vector<ll> res;
  for(auto &el : list) cin >> el.first >> el.second;
  for(ll i = m-1; i >= 0; i--){
    if(!vis[list[i].first] && !vis[list[i].second]){
      res.push_back(i);
      vis[list[i].first] = true;
      vis[list[i].second] = true;
    }
  }
  sort(res.begin(), res.end());
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


  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}