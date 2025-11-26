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
const ll MOD = 1e9+7;

struct SegTree{
  vector<ll> sums,prop;
  ll ss;
  SegTree(ll n){
    ss = 1;
    while(ss < n) ss <<= 1;
    sums.assign(ss<<1, 1);
    prop.assign(ss<<1, 1);
  }
  void propagate(ll x){
    sums[x] = (sums[x]*prop[x])%MOD;
    if(x < ss-1){ // if x isn't a leaf node
      prop[2*x+1] = (prop[2*x+1]*prop[x]) % MOD;
      prop[2*x+2] = (prop[2*x+2]*prop[x]) % MOD;
    }
    prop[x] = 1;
  }
  void set(ll l, ll r, ll v, ll x, ll lx, ll rx){
    propagate(x);
    if(l <= lx && rx <= r){
      prop[x] = (prop[x]*v) % MOD;
      propagate(x);
      return;
    }
    if(lx > r || rx < l) return;
    ll mid = (lx+rx)/2;
    set(l,r,v,2*x+1,lx,mid);
    set(l,r,v,2*x+2,mid+1,rx);
    sums[x] = (sums[2*x+1] + sums[2*x+2]) % MOD;
  }
  void set(ll l, ll r, ll v){
    set(l,r,v,0,0,ss-1);
  }
  ll get(ll l, ll r, ll x, ll lx, ll rx){
    propagate(x);
    if(l <= lx && rx <= r){
      return sums[x];
    }
    if(lx > r || rx < l) return 0;

    ll mid = (lx+rx)/2;
    ll lewo = get(l,r,2*x+1,lx,mid);
    ll prawo = get(l,r,2*x+2,mid+1,rx);
    sums[x] = (sums[2*x+1] + sums[2*x+2]) % MOD;
    return (lewo+prawo) % MOD;
  }
  ll get(ll l, ll r){
    return get(l,r,0,0,ss-1);
  }
  void print(){
    for(auto el : prop) cout << el << ' ';
    cout << endl;
    for(auto el : sums) cout << el << ' ';
    cout << endl; 
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n);
  for(int i = 0; i < n; i++) segtree.get(i,i);
  for(int i = 0; i < m; i++){
    cin >> t;
    if(t == 1){
      cin >> l >> r >> v;
      r--;
      segtree.set(l,r,v);
    } else{
      cin >> l >> r;
      r--;
      // segtree.print();
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