#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
int t,l,r,v;

struct SegTree{
  vector<int> nodes, prop;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss<<=1;
    nodes.assign(ss<<1, 0);
    prop.assign(ss<<1, 0);
  }
  void propagate(int x){
    nodes[x] |= prop[x];
    if(x < ss-1){
      prop[2*x+1] |= prop[x];
      prop[2*x+2] |= prop[x];
    }
    prop[x] = 0;
  }
  void set(int l, int r, int v, int x, int lx, int rx){
    propagate(x);
    if(l <= lx && rx <= r){
      prop[x] |= v;
      propagate(x);
      return;
    }
    if(r < lx || rx < l) return;
    int mid = (lx+rx)/2;
    set(l,r,v,2*x+1,lx,mid);
    set(l,r,v,2*x+2,mid+1,rx);
    nodes[x] = nodes[2*x+1] & nodes[2*x+2];
  }
  void set(int l, int r, int v){
    set(l,r,v,0,0,ss-1);
  }
  int get(int l, int r, int x, int lx, int rx){
    propagate(x);
    // dbg(x,lx,rx,nodes[x],prop[x]);
    if(l <= lx && rx <= r) return nodes[x];
    if(r < lx || rx < l) return ~0; //wszystkie bity ustawione
    int mid = (lx+rx)/2;
    int jeden = get(l,r,2*x+1,lx,mid);
    int dwa = get(l,r,2*x+2,mid+1,rx);
    nodes[x] = nodes[2*x+1] & nodes[2*x+2];
    return jeden & dwa;
  }
  int get(int l, int r){
    return get(l,r,0,0,ss-1);
  }
  void print(){
    for(auto el : nodes) cout << el << ' ';
    cout << endl;
    for(auto el : prop) cout << el << ' ';
    cout << endl;
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
      // segtree.print();
    } else{
      cin >> l >> r;
      cout << segtree.get(l,r-1) << endl;
      // for(int j = l; j < r; j++) cout << segtree.get(j,j) << ' ';
      // segtree.print();
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