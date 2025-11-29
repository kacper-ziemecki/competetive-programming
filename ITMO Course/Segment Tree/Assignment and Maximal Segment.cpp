#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m,l,r,v;

struct Node{
  ll pref,sum,suf,mx;
  Node(){
    pref=0;
    sum=0;
    suf=0;
    mx=0;
  }
};

struct SegTree{
  vector<Node> nodes;
  vector<ll> prop;
  Node I;
  ll ss;
  SegTree(ll n){
    ss = 1;
    while(ss < n) ss <<= 1;
    nodes.assign(ss<<1, I);
    prop.assign(ss<<1, LLONG_MAX);
  }
  void propagate(ll x, ll lx, ll rx){
    if(prop[x] == LLONG_MAX) return;
    nodes[x].sum = prop[x] * (rx-lx+1);
    if(prop[x] > 0){
      nodes[x].pref = nodes[x].suf = nodes[x].mx = prop[x] * (rx-lx+1);
    } else{
      nodes[x].pref = nodes[x].suf = nodes[x].mx = 0;
    }

    if(x < ss-1){
      prop[2*x+1] = prop[x];
      prop[2*x+2] = prop[x]; 
    }
    prop[x] = LLONG_MAX;
  }
  Node combine(Node &lewo, Node &prawo){
    Node tmp;
    tmp.sum = lewo.sum + prawo.sum;
    tmp.pref = max(lewo.pref, lewo.sum+prawo.pref);
    tmp.suf = max(lewo.suf+prawo.sum, prawo.suf);
    tmp.mx = max({lewo.mx, prawo.mx, lewo.suf+prawo.pref});
    return tmp;
  }
  void set(ll l, ll r, ll v, ll x, ll lx, ll rx){
    propagate(x,lx,rx);
    if(l <= lx && rx <= r){
      prop[x] = v;
      propagate(x,lx,rx);
      return;
    }
    if(lx > r || rx < l) return;
    ll mid = (lx+rx)/2;
    set(l,r,v,2*x+1,lx,mid);
    set(l,r,v,2*x+2,mid+1,rx);
    nodes[x] = combine(nodes[2*x+1], nodes[2*x+2]);
  }
  void set(ll l, ll r, ll v){
    set(l,r,v,0,0,ss-1);
  }
  Node get(ll l, ll r, ll x, ll lx, ll rx){
    propagate(x,lx,rx);
    if(l <= lx && rx <= r) return nodes[x];
    if(lx > r || rx < l) return I;
    ll mid = (lx+rx)/2;
    Node jeden = get(l,r,2*x+1,lx,mid);
    Node dwa = get(l,r,2*x+2,mid+1,rx);
    nodes[x] = combine(nodes[2*x+1], nodes[2*x+2]);
    return combine(jeden,dwa);
  }
  ll get(ll l, ll r){
    return get(l,r,0,0,ss-1).mx;
  }
  void print(){
    for(auto el : nodes){
      cout << el.mx << ' ';
    }
    cout << endl;
    for(auto el : prop){
      cout << el << ' ';
    }
    cout << endl;
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n);
  for(int i = 0; i < m; i++){
    cin >> l >> r >> v;
    segtree.set(l,r-1,v);
    // segtree.print();
    cout << segtree.get(0, n-1) << endl;
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