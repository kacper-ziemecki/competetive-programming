#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m,t,l,r,k;

struct SegTree{
  vector<ll> nodes;
  vector<bool> prop;
  ll ss;
  SegTree(ll n){
    ss = 1;
    while(ss < n) ss <<= 1;
    nodes.assign(ss<<1, 0);
    prop.assign(ss<<1, true);
  }
  void propagate(ll x, ll lx, ll rx){
    if(prop[x]) return;
    nodes[x] = (rx-lx+1) - nodes[x];
    if(x < ss-1){
      prop[2*x+1] = !prop[2*x+1];
      prop[2*x+2] = !prop[2*x+2];
    }
    prop[x] = true;
  }
  void set(ll l, ll r, ll x, ll lx, ll rx){
    propagate(x,lx,rx);
    if(l <= lx && rx <= r){
      prop[x] = !prop[x];
      propagate(x,lx,rx);
      return;
    }
    if(rx < l || r < lx) return;
    ll mid = (lx+rx)/2;
    set(l,r,2*x+1,lx,mid);
    set(l,r,2*x+2,mid+1,rx);
    nodes[x] = nodes[2*x+1] + nodes[2*x+2];
  }
  void set(ll l, ll r){
    set(l,r,0,0,ss-1);
  }
  ll get(ll k, ll x, ll lx, ll rx){
    propagate(x,lx,rx);
    // dbg(k,x,lx,rx);
    if(lx==rx) return lx;
    ll mid = (lx+rx)/2;
    propagate(2*x+1, lx, mid);
    if(nodes[2*x+1] >= k) return get(k,2*x+1,lx,mid);
    return get(k-nodes[2*x+1],2*x+2,mid+1,rx);
  }
  ll get(ll k){
    return get(k,0,0,ss-1);
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n);
  for(int i = 0; i < m; i++){
    cin >> t;
    if(t==1){
      cin >> l >> r;
      segtree.set(l,r-1);
    } else{
      cin >> k;
      cout << segtree.get(k+1) << endl;
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