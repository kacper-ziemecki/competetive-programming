#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
int p,ta,tb;
const int maxn = 2e5+1;
vector<ll> adj[maxn];
ll pref[maxn];
map<pair<ll,ll>, ll> a,b;

void dfs(int u, ll p, vector<ll>& prefix, ll sumaA = 0){
  ll idx = upper_bound(prefix.begin(), prefix.end(), sumaA) - prefix.begin();
  pref[u] = idx;
  for(auto v : adj[u]){
    if(prefix.empty()) prefix.pb(b[{u,v}]);
    else prefix.pb(prefix.back()+b[{u,v}]);
    dfs(v,u,prefix,sumaA+a[{u,v}]);
    prefix.pop_back();
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i <= n; i++){
    pref[i] = 0;
    adj[i].clear();
  }
  a.clear();
  b.clear();
  for(int i = 2; i <= n; i++){
    cin >> p >> ta >> tb;
    a[{p,i}] = ta;
    b[{p,i}] = tb;
    adj[p].pb(i);
  }
  vector<ll> prefix;
  dfs(1, -1, prefix);
  for(int i = 2; i <= n; i++) cout << pref[i] << ' ';
  cout << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  int t;
  cin >> t;
  while(t--)
  solve();
}