#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


class Segtree {
public:
  ll size;
  vector<ll> sums;
  vector<ll> lazy;
  Segtree(ll n){
    size = 1;
    while(size < n) size <<= 1;
    sums.assign(2*size, 0ll);
    lazy.assign(2*size, 0ll);
  }
  void set(ll l, ll r, ll v, ll x, ll lx, ll rx){
    if(lx >= l && rx <= r){ lazy[x]+=v;return; }
    if(lx >= r || rx <= l) return;
    ll m = (lx+rx)/2;
    set(l, r, v, 2*x+1, lx, m);
    set(l, r, v, 2*x+2, m, rx);
  }
  void set(ll l, ll r, ll v){
    set(l, r, v, 0, 0, size);
  }

  ll sum(ll l, ll r, ll x, ll lx, ll rx){
    if(lazy[x]){
      sums[x]+=lazy[x];
      if(2*x+1 < 2*size) lazy[2*x+1] += lazy[x];
      if(2*x+2 < 2*size) lazy[2*x+2] += lazy[x];
      lazy[x] = 0;
    }
    if(rx <= l || lx >= r) return 0;
    if(lx >= l && rx <= r) return sums[x];
    ll m = (lx+rx)/2;
    ll s1 = sum(l, r, 2*x+1, lx, m);
    ll s2 = sum(l, r, 2*x+2, m, rx);
    return s1+s2;
  }
  ll sum(ll l, ll r){
    return sum(l, r, 0, 0, size);
  }
};


void solve(){
  ll n,m,tmp;
  cin >> n >> m;
  Segtree segtree(n);
  ll a,b,c,d;
  for(ll i = 0; i < m; i++){
    cin >> a;
    if(a == 1){
      cin >> b >> c >> d;
      segtree.set(b, c, d);
    } else{
      cin >> b;
      cout << segtree.sum(b, b+1) << endl;
    }
    // for(auto el : segtree.sums) cout << el << " ";
    // cout << endl;
    // for(auto el : segtree.lazy) cout << el << " ";
    // cout << endl;
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