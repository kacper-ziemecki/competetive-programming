#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
const int maxn = 2e5+1;
int hotels[maxn], grupy[maxn];

struct SegTree{
  vector<int> nodes;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss<<=1;
    nodes.assign(ss<<1, 0);
  }
  void set(int idx, int val, int x, int lx, int rx){
    if(lx == idx && rx == idx){
      nodes[x] = val;
      return;
    }
    if(idx < lx || rx < idx) return;
    int mid = (lx+rx)/2;
    set(idx,val,2*x+1,lx,mid);
    set(idx,val,2*x+2,mid+1,rx);
    nodes[x] = max(nodes[2*x+1], nodes[2*x+2]);
  }
  void set(int idx, int val){
    set(idx,val,0,1,ss);
  }
  void subtract(int idx, int val, int x, int lx, int rx){
    // dbg(lx,rx);
    if(lx == idx && rx == idx){
      nodes[x] -= val;
      // dbg("subtract",lx,rx);
      return;
    }
    if(idx < lx || rx < idx) return;
    int mid = (lx+rx)/2;
    subtract(idx,val,2*x+1,lx,mid);
    subtract(idx,val,2*x+2,mid+1,rx);
    nodes[x] = max(nodes[2*x+1], nodes[2*x+2]);
  }
  void subtract(int idx, int val){
    subtract(idx,val,0,1,ss);
  }
  int getMax(int k, int x, int lx, int rx){
    // dbg(lx,rx);
    if(lx == rx) return lx;
    int mid = (lx+rx)/2;
    if(nodes[2*x+1] >= k) return getMax(k,2*x+1,lx,mid);
    else return getMax(k,2*x+2,mid+1,rx);
  }
  int getMax(int k){
    return getMax(k,0,1,ss);
  }
  int getVal(int k, int x, int lx, int rx){
    // dbg(lx,rx);
    if(lx == rx) return nodes[x];
    int mid = (lx+rx)/2;
    if(k <= mid) return getVal(k,2*x+1,lx,mid);
    else return getVal(k,2*x+2,mid+1,rx);
  }
  int getVal(int k){
    return getVal(k,0,1,ss);
  }
};

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> hotels[i];
  for(int i = 0; i < m; i++) cin >> grupy[i];
  SegTree segtree(n+1);
  for(int i = 0; i < n; i++) segtree.set(i+1, hotels[i]);
  for(int i = 0; i < m; i++){
    // for(auto el : segtree.nodes) cout << el << ' ';
    // cout << endl;
    int idx = segtree.getMax(grupy[i]);
    // dbg(idx);
    // dbg(idx,segtree.getVal(idx),grupy[i]);
    if(segtree.getVal(idx) < grupy[i]){
      cout << 0 << ' ';
    } else{
      // dbg(idx);
      segtree.subtract(idx, grupy[i]);
      cout << idx << ' ';
    }
  }
  cout << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}