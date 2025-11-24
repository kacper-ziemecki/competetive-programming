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
int t,idx,h,lewo,prawo,p;

struct SegTree{
  vector<int> nodes;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    nodes.assign(ss<<1, INT_MAX);
  }
  void print(){
    for(auto el : nodes) cout << el << ' ';
    cout << endl;
  }
  void set(int idx, int val, int x, int lx, int rx){
    if(lx==rx){
      nodes[x] = val;
      return;
    }
    int mid = (lx+rx)/2;
    if(idx <= mid) set(idx,val,2*x+1,lx,mid);
    else set(idx,val,2*x+2,mid+1,rx);
    nodes[x] = min(nodes[2*x+1], nodes[2*x+2]);
  }
  void set(int idx, int val){
    set(idx,val,0,0,ss-1);
  }
  int get(int l, int r, int p, int x, int lx, int rx){
    // dbg(l,r,p,lx,rx);
    if(lx > r || rx < l || nodes[x] > p) return INT_MAX;
    if(lx==rx) return (nodes[x] <= p ? lx : INT_MAX);
    int mid = (lx+rx)/2;
    int jeden=INT_MAX;
    jeden = get(l,r,p,2*x+1,lx,mid);
    if(jeden != INT_MAX) return jeden;
    return get(l,r,p,2*x+2,mid+1,rx);
  }
  int get(int l, int r, int p){
    return get(l,r,p,0,0,ss-1);
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n+1);
  for(int i = 0; i < m; i++){
    cin >> t;
    if(t == 1){
      cin >> idx >> h;
      segtree.set(idx,h);
    } else{
      cin >> lewo >> prawo >> p;
      prawo--;
      int indeks = segtree.get(lewo,prawo,p);
      int res = 0;
      while(indeks != INT_MAX){
        segtree.set(indeks, INT_MAX);
        res++;
        indeks = segtree.get(lewo,prawo,p);
      }
      // dbg(lewo,prawo,p);
      cout << res << endl;
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