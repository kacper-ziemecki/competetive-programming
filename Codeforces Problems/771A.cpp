#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p, _size, num;

ll find_set(ll a){ return (a == p[a] ? a : p[a] = find_set(p[a])); }
void union_set(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b){ num[a]++; return; }
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
  num[a] += num[b] + 1;
}


void solve()
{
  ll n,m,u,v;
  cin >> n >> m;
  vector<pair<ll,ll>> edges(m);
  p.assign(n+1, 0); _size.assign(n+1, 1); num.assign(n+1, 0);
  for(ll i = 0; i < n+1; i++) p[i] = i;
  for(auto &edge : edges) cin >> edge.first >> edge.second;
  for(auto edge : edges){
    union_set(edge.first, edge.second);
  }
  for(ll i = 1; i < n+1; i++){
    // dbg(i, p[find_set(i)], num[find_set(i)], _size[find_set(i)]);
    if(num[find_set(i)] != 0 && num[find_set(i)] != (_size[find_set(i)]*(_size[find_set(i)]-1))/2){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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