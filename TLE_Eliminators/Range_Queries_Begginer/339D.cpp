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

int n,m,idx,val;
struct SegTree{
  vector<int> nodes;
  int ss,height;
  SegTree(int n){
    ss = 1;
    height=0;
    while(ss < n){
      ss<<=1;
      height++;
    }
    nodes.assign(ss<<1,0);
  }
  void set(int idx, int val, int x, int lx, int rx, int depth){
    if(lx == idx && rx == idx){
      nodes[x] = val;
      return;
    }
    if(rx < idx || lx > idx) return;
    int mid = (lx+rx)/2;
    set(idx,val,2*x+1,lx,mid,depth-1);
    set(idx,val,2*x+2,mid+1,rx,depth-1);
    if(depth&1) nodes[x] = nodes[2*x+1] | nodes[2*x+2];
    else nodes[x] = nodes[2*x+1] ^ nodes[2*x+2];
  }
  void set(int idx, int val){
    set(idx,val,0,1,ss,height);
  }
  int get(){
    return nodes[0];
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(1<<n+1);
  for(int i = 1; i <= 1<<n; i++){
    cin >> val;
    segtree.set(i,val);
  }
  for(int i = 0; i < m; i++){
    cin >> idx >> val;
    segtree.set(idx,val);
    cout << segtree.get() << endl;
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