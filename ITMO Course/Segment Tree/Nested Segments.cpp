#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
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
  ll sum(ll l, ll r, ll x, ll lx, ll rx){
    if(lx >= r || rx <= l) return 0;
    if(lx >= l && rx <= r) return sums[x];
    ll m = (lx+rx)/2;
    ll s1 = sum(l,r,2*x+1,lx,m);
    ll s2 = sum(l,r,2*x+2,m,rx);
    return s1+s2;
  }
  ll sum(ll l, ll r){
    return sum(l,r,0,0,size);
  }
};

void solve(){
  ll n;
  cin >> n;
  n *= 2;
  vector<ll> list(n, 0), one(n+1,0), res(n+1,0);
  Segtree sgtree(n+1);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    ll el = list[i];
    if(one[el] != 0){
      res[el] = sgtree.sum(one[el], i+1);
      sgtree.set(one[el], 1);
    } else{
      one[el] = i+1;
    }
  }
  for(ll i = 1; i <= n/2; i++){
    cout << res[i] << " ";
  }
  cout << endl;
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