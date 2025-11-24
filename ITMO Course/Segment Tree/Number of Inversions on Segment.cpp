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
  vector<vector<ll>> list;
  vector<ll> inv;
  Segtree(ll n){
    size = 1;
    while(size < n) size <<= 1;
    list.assign(2*size, vector<ll>(41, 0ll));
    inv.assign(2*size, 0);
  }
  vector<ll> calcList(vector<ll>& l1, vector<ll>& l2){
    vector<ll> res(41, 0);
    for(ll i = 1; i < 41; i++) res[i] = l1[i]+l2[i];
    return res;
  }
  ll calcInv(vector<ll>& l1, vector<ll>& l2, ll i1, ll i2){
    ll res = i1+i2;

    ll size1 = 0;
    for(auto el : l1) size1 += el;
    dbg(size1);
    for(ll i = 1; i < 41; i++){
      size1 -= l1[i];
      res += l2[i] * size1;
    }
    return res;
  }

  void set(ll i, ll v, ll x, ll lx, ll rx){
    if(rx-lx==1){
      list[x].assign(41, 0ll);
      list[x][v] = 1;
      return;
    }
    ll m = (lx+rx)/2;
    if(i < m) set(i, v, 2*x+1, lx, m);
    else set(i, v, 2*x+2, m, rx);
    list[x] = calcList(list[2*x+1], list[2*x+2]);
    inv[x] = calcInv(list[2*x+1], list[2*x+2], inv[2*x+1], inv[2*x+2]);
  }
  void set(ll i, ll v){
    set(i, v, 0, 0, size);
  }
  pair<ll, vector<ll>> inversion(ll l, ll r, ll x, ll lx, ll rx){
    if(lx >= l && rx <= r) return {inv[x], list[x]};
    if(lx >= r || rx <= l) return {0, vector<ll>(41, 0ll)};
    ll m = (lx+rx)/2;
    pair<ll, vector<ll>> inv1 = inversion(l, r, 2*x+1, lx, m);
    pair<ll, vector<ll>> inv2 = inversion(l, r, 2*x+2, m, rx);
    return {calcInv(inv1.second, inv2.second, inv1.first, inv2.first), calcList(inv1.second, inv2.second)};
  }
  ll inversion(ll l, ll r){
    return inversion(l, r, 0, 0, size).first;
  }
};

void solve(){
  ll n,q;
  cin >> n >> q;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  Segtree segtree(n);
  for(ll i = 0; i < n; i++) segtree.set(i, list[i]);
  for(auto el : segtree.inv) cout << el << " ";
  cout << endl;
  ll a,b,c;
  for(ll i = 0; i < q; i++){
    cin >> a >> b >> c;
    if(a == 1){
      cout << segtree.inversion(b-1, c-1) << endl;
    } else{
      segtree.set(b-1, c);
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