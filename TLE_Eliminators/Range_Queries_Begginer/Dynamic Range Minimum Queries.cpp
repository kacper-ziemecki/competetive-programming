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

int n,q;
int l,r,a,b,t;

struct SegTree{
  vector<int> mn;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss<<=1;
    mn.assign(ss<<1, 0);
  }
  void set(int idx, int val, int x, int lx, int rx){
    if(lx == idx && rx == idx){
      mn[x] = val;
      return;
    }
    if(lx > idx || rx < idx) return;
    int mid = (lx+rx)/2;
    set(idx,val,2*x+1,lx,mid);
    set(idx,val,2*x+2,mid+1,rx);
    mn[x] = min(mn[2*x+1],mn[2*x+2]);
  }
  void set(int idx, int val){
    set(idx,val,0,1,ss);
  }
  int get(int l, int r, int x, int lx, int rx){
    if(l <= lx && rx <= r) return mn[x];
    if(lx > r || rx < l) return INT_MAX;
    int mid = (lx+rx)/2;
    return min(get(l,r,2*x+1,lx,mid),get(l,r,2*x+2,mid+1,rx));
  }
  int get(int l, int r){
    return get(l,r,0,1,ss);
  }
};

void solve(){
  cin >> n >> q;
  SegTree segtree(n+1);
  for(int i = 0; i < n; i++){
    cin >> a;
    segtree.set(i+1,a);
  }
  for(int i = 0; i < q; i++){
    cin >> t;
    if(t == 1){
      cin >> a >> b;
      segtree.set(a,b);
    } else{
      cin >> l >> r;
      cout << segtree.get(l,r) << endl;
    }
  }
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