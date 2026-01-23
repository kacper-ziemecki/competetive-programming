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
int x,y,t;

struct SegTree{
  vector<int> mn,cnt;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    mn.assign(ss<<1,INT_MAX);
    cnt.assign(ss<<1, 1);
  }
  void set(int idx, int val, int x, int lx, int rx){
    if(lx > idx || rx < idx) return;
    if(lx == rx){
      mn[x] = val;
      return;
    }
    int mid = (lx+rx)/2;
    set(idx,val,2*x+1,lx,mid);
    set(idx,val,2*x+2,mid+1,rx);
    mn[x] = min(mn[2*x+1], mn[2*x+2]);
    cnt[x] = (mn[2*x+1] == mn[2*x+2] ? cnt[2*x+1]+cnt[2*x+2] : (mn[2*x+1] < mn[2*x+2] ? cnt[2*x+1] : cnt[2*x+2]));
  }
  void set(int idx, int val){
    set(idx,val,0,0,ss-1);
  }
  pair<int,int> get(int l, int r, int x, int lx, int rx){
    if(l <= lx && rx <= r) return make_pair(mn[x],cnt[x]);
    if(lx > r || rx < l) return make_pair(INT_MAX, 0);
    int mid = (lx+rx)/2;
    pair<int,int> res = {0,0};
    pair<int,int> lewo = get(l,r,2*x+1,lx,mid);
    pair<int,int> prawo = get(l,r,2*x+2,mid+1,rx);
    res.first = min(lewo.first,prawo.first);
    res.second = (lewo.first == prawo.first ? lewo.second+prawo.second : (lewo.first < prawo.first ? lewo.second : prawo.second));
    return res;
  }
  pair<int,int> get(int l, int r){
    return get(l,r,0,0,ss-1);
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n);
  for(int i = 0; i < n; i++){
    cin >> x;
    segtree.set(i,x);
  }
  for(int i = 0; i < m; i++){
    cin >> t >> x >> y;
    if(t == 1){
      segtree.set(x,y);
    } else{
      pair<int,int> res = segtree.get(x,y-1);
      cout << res.first << ' ' << res.second << endl;
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