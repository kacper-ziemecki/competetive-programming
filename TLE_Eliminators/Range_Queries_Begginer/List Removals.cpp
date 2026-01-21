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

int n;
const int maxn = 2e5+1;
int lista[maxn], erasing[maxn];

struct SegTree{
  vector<int> nodes;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    nodes.assign(ss<<1, 0);
  }
  void set(int idx, int val, int x, int lx, int rx){
    if(lx == idx && rx == idx){
      nodes[x] = val;
      return;
    }
    if(lx > idx || rx < idx) return;
    int mid = (lx+rx)/2;
    set(idx,val,2*x+1,lx,mid);
    set(idx,val,2*x+2,mid+1,rx);
    nodes[x] = nodes[2*x+1] + nodes[2*x+2];
  }
  void set(int idx, int val){
    set(idx,val,0,1,ss);
  }
  int get(int k, int x, int lx, int rx){
    // dbg(lx,rx,k);
    if(lx==rx) return lx;
    int mid = (lx+rx)/2;
    if(nodes[2*x+1] >= k) return get(k,2*x+1,lx,mid);
    else return get(k-nodes[2*x+1],2*x+2,mid+1,rx);
  }
  int get(int k){
    return get(k,0,1,ss);
  }
};

void solve(){
  cin >> n;
  SegTree segtree(n+1); // 1-based indexing
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < n; i++) cin >> erasing[i];
  for(int i = 1; i <= n; i++) segtree.set(i,1);
  // for(auto el : segtree.nodes) cout << el << ' ';
  // cout << endl;
  for(int i = 0; i < n; i++){
    // dbg(erasing[i]);
    int idx = segtree.get(erasing[i]);
    // dbg(idx, lista[idx-1]);
    cout << lista[idx-1] << ' ';
    segtree.set(idx,0);
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