#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m,t,l,r,v;

struct SegTree{
  vector<ll> nodes,prop;
  ll ss;
  SegTree(ll n){
    ss = 1;
    while(ss < n) ss <<= 1;
    nodes.assign(ss<<1, 0);
    prop.assign(ss<<1, -1);
  }
  void propagate(ll x){
    if(prop[x] == -1) return;
    nodes[x] = prop[x];
    if(x < ss-1){
      prop[2*x+1] = prop[x];
      prop[2*x+2] = prop[x];
    }
    prop[x] = -1;
  }
  void set(ll l, ll r, ll v, ll x, ll lx, ll rx){
    propagate(x);
    if(l <= lx && rx <= r){
      prop[x] = v;
      propagate(x);
      return;
    }
    if(rx < l || r < lx) return;
    ll mid = (lx+rx)/2;
    set(l,r,v,2*x+1,lx,mid);
    set(l,r,v,2*x+2,mid+1,rx);
    nodes[x] = min(nodes[2*x+1], nodes[2*x+2]);
  }
  void set(ll l, ll r, ll v){
    set(l,r,v,0,0,ss-1);
  }
  ll get(ll l, ll r, ll x, ll lx, ll rx){
    propagate(x);
    if(l <= lx && rx <= r) return nodes[x];
    if(rx < l || r < lx) return LLONG_MAX;
    ll mid = (lx+rx)/2;
    ll jeden = get(l,r,2*x+1,lx,mid);
    ll dwa = get(l,r,2*x+2,mid+1,rx);
    nodes[x] = min(nodes[2*x+1], nodes[2*x+2]);
    return min(jeden, dwa);
  }
  ll get(ll l, ll r){
    return get(l,r,0,0,ss-1);
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n);
  for(ll i = 0; i < m; i++){
    cin >> t;
    if(t == 1){
      cin >> l >> r >> v;
      segtree.set(l,r-1,v);
    } else{
      cin >> l >> r;
      cout << segtree.get(l,r-1) << endl;
    }
  }
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

  solve();
}