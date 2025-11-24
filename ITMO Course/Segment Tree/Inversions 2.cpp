#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

class Segtree{
public:
  ll size;
  vector<ll> sums;
  Segtree(ll n){
    size = 1;
    while(size < n) size <<= 1;
    sums.assign(2*size, 0ll);
  }
  void set(ll i, ll v, ll x, ll lx, ll rx){
    if(rx-lx==1){
      sums[x]=v;
      return;
    }
    ll m = (lx+rx)/2;
    if(i < m) set(i,v,2*x+1,lx,m);
    else set(i,v,2*x+2,m,rx);
    sums[x] = sums[2*x+1]+sums[2*x+2];
  }
  void set(ll i, ll v){
    set(i,v,0,0,size);
  }
  ll find_el(ll k, ll x, ll lx, ll rx){
    if(rx-lx==1){
      return lx;
    }
    ll m = (rx+lx)/2;
    if(k <= sums[2*x+1]){
      return find_el(k,2*x+1,lx,m);
    }
    else{
      return find_el(k-sums[2*x+1],2*x+2,m,rx);
    }
  }
  ll find_el(ll k){
    return find_el(k,0,0,size);
  }
};

void solve()
{
  ll n,number=0;
  cin >> n;
  number=n;
  vector<ll> list(n, 0), res(n, 0);
  for(auto &el : list) cin >> el;
  Segtree sgtree(n+1);
  for(ll i = 1; i <= n; i++) sgtree.set(i, 1);
  for(ll i = n-1; i >= 0; i--){
    ll el = list[i];
    res[i] = sgtree.find_el(number-el);
    sgtree.set(sgtree.find_el(number-el), 0);
    number--;
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
  
}