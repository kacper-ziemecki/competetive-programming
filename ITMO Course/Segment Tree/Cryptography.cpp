#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll MOD;
map< pair<ll, ll>, vector<ll> > mp;

class Segtree{
public:
  ll size;
  vector<vector<ll>> products;
  void init(ll x, ll lx, ll rx){
    if(rx-lx==1) return;
    ll m = (lx+rx)/2;
    init(2*x+1, lx, m);
    init(2*x+2, m, rx);
    products[x] = calc(products[2*x+1], products[2*x+2]);
  }
  Segtree(vector<vector<ll>> &list){
    size = 1;
    while(size < list.size()) size <<= 1;
    products.assign(2*size, vector<ll>(4, 0ll));
    for(ll i = size-1; i < size+list.size()-1; i++) products[i] = list[i-(size-1)];
    init(0, 0, size);
  }
  vector<ll> calc(vector<ll> &l1, vector<ll> &l2){
    vector<ll> res(4, 0);
    res[0] = (l1[0]*l2[0]+l1[1]*l2[2])%MOD;
    res[1] = (l1[0]*l2[1]+l1[1]*l2[3])%MOD;
    res[2] = (l1[2]*l2[0]+l1[3]*l2[2])%MOD;
    res[3] = (l1[2]*l2[1]+l1[3]*l2[3])%MOD;
    return res;
  }

  vector<ll> product(ll l, ll r, ll x, ll lx, ll rx){
    if(lx >= l && rx <= r) return products[x];
    if(rx <= l || lx >= r) return {1, 0, 0, 1};
    ll m = (lx+rx)/2;
    vector<ll> p1 = product(l, r, 2*x+1, lx, m);
    vector<ll> p2 = product(l, r, 2*x+2, m, rx);
    return calc(p1, p2);
  }
  vector<ll> product(ll l, ll r){
    return product(l, r, 0, 0, size);
  }
};

void solve(){
  ll n,m, left, right;
  cin >> MOD >> n >> m;
  vector<vector<ll>> list(n, vector<ll>(4, 0ll));
  vector<ll> tmp;
  for(auto &sub : list){
    for(auto &el : sub) cin >> el;
  }
  Segtree segtree(list);
  for(ll i = 0; i < m; i++){
    cin >> left >> right;
    if(!mp[{left,right}].empty()){ tmp = mp[{left,right}];}
    else{ tmp = segtree.product(left-1, right); mp[{left,right}]=tmp;}
    for(ll i = 0; i < 4; i++){
      cout << tmp[i] << " ";
      if(i == 1 || i == 3) cout << endl;
    }
    cout << endl;
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