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
    prop.assign(ss<<1, 0);
  }
  void propagate(ll x){
    nodes[x] += prop[x];
    if(x < ss-1){
      prop[2*x+1] += prop[x];
      prop[2*x+2] += prop[x];
    }
    prop[x] = 0;
  }
  void set(ll l, ll r, ll v, ll x, ll lx, ll rx){
    propagate(x);
    if(l <= lx && rx <= r){
      prop[x] += v;
      propagate(x);
      return;
    }
    if(r < lx || rx < l) return;
    ll mid = (lx+rx)/2;
    set(l,r,v,2*x+1,lx,mid);
    set(l,r,v,2*x+2,mid+1,rx);
    nodes[x] = max(nodes[2*x+1], nodes[2*x+2]);
  }
  void set(ll l, ll r, ll v){
    set(l,r,v,0,0,ss-1);
  }
  ll get(ll l, ll v, ll x, ll lx, ll rx){
    propagate(x);
    if(nodes[x] < v || rx < l) return -1;
    if(lx == rx) return lx;
    ll mid = (lx+rx)/2;
    ll jeden = get(l,v,2*x+1,lx,mid);
    if(jeden != -1) return jeden;
    ll dwa = get(l,v,2*x+2,mid+1,rx);
    // nodes[x] = max(nodes[2*x+1], nodes[2*x+2]);
    return dwa;
  }
  ll get(ll l, ll v){
    return get(l,v,0,0,ss-1);
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n);
  for(int i = 0; i < m; i++){
    cin >> t;
    if(t==1){
      cin >> l >> r >> v;
      segtree.set(l,r-1,v);
    } else{
      cin >> v >> l;
      cout << segtree.get(l,v) << endl;
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