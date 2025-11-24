#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p,r;
ll findSet(ll u){
  return (u == p[u] ? u : p[u] = findSet(p[u]));
}
void unionSet(ll u, ll v){
  u = findSet(u);
  v = findSet(v);
  if(u == v) return;
  if(r[u] < r[v]) swap(u, v);
  p[v] = u;
  r[u]++;
}

void solve(ll n,ll m){
  vector<tuple<ll,ll,ll>> edges(m),res;
  for(auto &el : edges) cin >> get<1>(el) >> get<2>(el) >> get<0>(el);
  sort(edges.begin(), edges.end());
  p.assign(n+1, 1);
  r.assign(n+1, 1);
  for(ll i = 0; i <= n; i++) p[i]=i;
  for(auto edge : edges){
    if(findSet(get<1>(edge)) != findSet(get<2>(edge))){
      unionSet(get<1>(edge), get<2>(edge));
    } else{
      res.push_back(edge);
    }
  }
  if(res.empty()){
    cout << "forest";
  }
  for(ll i = 0; i < res.size(); i++){
    if(i != 0) cout << " ";
    cout << get<0>(res[i]);
  }
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

  ll n,m;
  while(cin >> n >> m, n != 0 || m != 0){
    solve(n,m);
  }
}