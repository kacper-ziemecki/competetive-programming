#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p, _size;

ll find_set(ll a){
  return (p[a] == a ? a : p[a] = find_set(p[a]));
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> edges(m, vector<ll>(3, 0));
  ll u,v,w;
  
  p.assign(n+1, 0); _size.assign(n+1, 1);
  for(ll i = 0; i < n+1; i++) p[i] = i;

  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    edges[i] = {w,u,v};
  }
  sort(edges.begin(), edges.end());
  ll res = 0;
  for(auto edge : edges){
    if(find_set(edge[1]) != find_set(edge[2])){
      res += edge[0];
      union_sets(edge[1], edge[2]);
    }
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

  solve();
}