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

class SegTree{
public:
  vector<ll> tree;
  ll size;
  SegTree(ll n){
    size = 1;
    while(size < n) size <<= 1;
    tree.assign(2*size, 0ll);
  }
  void set(ll i, ll v, ll x, ll lx, ll rx){
    if(rx-lx == 1){
      tree[x] = v;
      return;
    }
    ll mid = (lx+rx)/2;
    if(i < mid){
      set(i,v,2*x+1,lx,mid);
    } else{
      set(i,v,2*x+2,mid,rx);
    }
    tree[x] = tree[2*x+1] + tree[2*x+2];
  }
  void set(ll i, ll v){ set(i,v,0,0,size); }

  ll get(ll l, ll r, ll x, ll lx, ll rx){
    if(l <= lx && r >= rx) return tree[x];
    if(l >= rx || r <= lx) return 0;
    ll mid = (lx+rx)/2;
    return get(l,r,2*x+1,lx,mid) + get(l,r,2*x+2,mid,rx);
  }
  ll get(ll l, ll r){
    return get(l,r,0,0,size);
  }
};

void solve()
{
	ll n;
  cin >> n;
  vector<pair<ll,ll>> list(n);
  vector<ll> sorted(2*n);
  SegTree tree(2*n);
  for(auto &el : list) cin >> el.first >> el.second;
  map<ll, ll> poczotek, idx;
  map<ll, bool> pierwszy;
  for(auto el : list) pierwszy[el.first] = true;
  for(auto el : list) poczotek[el.second] = el.first;
  for(ll i = 0; i < n; i++){
    sorted[2*i] = list[i].first;
    sorted[2*i+1] = list[i].second;
  }
  sort(sorted.begin(), sorted.end());
  for(ll i = 0; i < 2*n; i++) idx[sorted[i]] = i;
  // for(auto el : sorted) cout << el << " ";
  // cout << endl;
  // for(auto el : pierwszy) cout << el.first << " " << el.second << endl;
  // cout << endl;
  ll res = 0;
  for(ll i = 0; i < 2*n; i++){
    if(pierwszy[sorted[i]]) tree.set(i, 1);
    else{
      tree.set(idx[poczotek[sorted[i]]], 0);
      // dbg(tree.get(0, idx[poczotek[sorted[i]]]), idx[poczotek[sorted[i]]]);
      res += tree.get(0, idx[poczotek[sorted[i]]]);
    }
    // for(auto el : tree.tree) cout << el << " ";
    // cout << endl;
    // dbg(res);
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