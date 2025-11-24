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
  ll n,x,y,res=0;
  cin >> n >> x >> y;
  vector<ll> list(n), one(n), two(n);
  map<pair<ll, ll>, vector<ll>> mp;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    one[i] = list[i]%x;
    two[i] = list[i]%y;
    mp[{one[i], two[i]}].push_back(list[i]);
  }
  for(auto &el : mp) sort(el.second.begin(), el.second.end());

  for(auto el : list) cout << el << " ";
  cout << endl;
  for(auto el : one) cout << el << " ";
  cout << endl;
  for(auto el : two) cout << el << " ";
  cout << endl;
  map<pair<ll,ll>,bool> vis;
  for(ll i = 0; i < n; i++){
    if(mp.count({(x-one[i])%x, two[i]}) == 0) continue;
    if(vis[{(x-one[i])%x, two[i]}]) continue;
    vis[{(x-one[i])%x, two[i]}]=true;
    dbg(i, (x-one[i])%x, two[i]);
    for(auto el : mp[{(x-one[i])%x,two[i]}]) cout << el << " ";
    cout << endl;
    ll tmp = mp[{(x-one[i])%x, two[i]}].size() - (lower_bound(mp[{(x-one[i])%x, two[i]}].begin(), mp[{(x-one[i])%x, two[i]}].end(), list[i])-mp[{(x-one[i])%x, two[i]}].begin());
    
    dbg(tmp);
    res += tmp;
  }
  dbg(res);
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