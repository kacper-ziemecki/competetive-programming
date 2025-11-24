#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct Binsearch{
  ll l,mid,r,farma;
  Binsearch(ll _l, ll _r, ll _farma){
    l = _l;
    mid = (_l+_r+1)/2;
    r = _r;
    farma = _farma;
  }
};

char c;
ll d,e;
ll n,q, ilosc_binsearchy;
const ll maxLiczba = 2e5+1;
vector<vector<ll>> input;
vector<vector<ll>> adds;
vector<Binsearch> bin[maxLiczba];
ll wyniki[maxLiczba];

struct DSU_with_rollback{
  vector<ll> parent, sajz, turned_off;
  stack<vector<ll>> unions,turn_offs;
  DSU_with_rollback(){}
  void resize(ll n){
    parent.resize(n+1);
    sajz.assign(n+1, 1);
    turned_off.assign(n+1, 0);
    for(ll i = 0 ; i <= n; i++) parent[i] = i;
  }
  void clear(){
    parent.clear();
    sajz.clear();
    turned_off.clear();
  }
  DSU_with_rollback(ll n){
    parent.resize(n+1);
    sajz.assign(n+1, 1);
    turned_off.assign(n+1, 0);
    for(ll i = 0 ; i <= n; i++) parent[i] = i;
  }
  ll findSet(ll a){
    return (a == parent[a] ? a : findSet(parent[a]));
  }
  void unionSets(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    unions.push({b, parent[b], a, sajz[a], a, turned_off[a]});
    if(sajz[a] < sajz[b]) swap(a, b);
    parent[b] = a;
    sajz[a] += sajz[b];
    turned_off[a] += turned_off[b];
  }
  void turn_off(ll a){
    a = findSet(a);
    turn_offs.push({a, turned_off[a]});
    turned_off[a]++;
  }
  void rollbackUnion(){
    vector<ll> before = unions.top(); unions.pop();
    parent[before[0]] = before[1];
    sajz[before[2]] = before[3];
    turned_off[before[4]] = before[5]; 
  }
  void rollbackTurnOff(){
    vector<ll> before = turn_offs.top(); turn_offs.pop();
    turned_off[before[0]] = before[1];
  }
};

struct Union{
  ll a,b;
  Union(ll _a, ll _b){a = _a; b = _b;}
};
struct TurnOff{
  ll a;
  TurnOff(ll _a){a = _a;}
};
// przedział-punkt
struct SegTree{
  vector< vector<Union> > unie;
  vector< vector<TurnOff> > offy;
  ll ss;
  SegTree(){}
  void resize(ll n){
    ss = 1;
    while(ss <= n) ss <<= 1;
    unie.assign(ss<<1, {});
    offy.assign(ss<<1, {});
  }
  void clear(){
    unie.clear();
    offy.clear();
  }
  SegTree(ll n){
    ss = 1;
    while(ss <= n) ss <<= 1;
    unie.assign(ss<<1, {});
    offy.assign(ss<<1, {});
  }
  // [l...r]
  void addUnion(ll l, ll r, Union &unia, ll lx, ll rx, ll x){
    dbg(l,r,lx,rx,x,unie.size());
    if(l <= lx && rx <= r){
      cout << "addUnion";
      dbg(l,r,lx,rx,x);
      unie[x].pb(unia);
      return;
    } else if(r < lx || rx < l) return;
    ll mid = (lx+rx)/2;
    addUnion(l,r,unia,lx,mid,x*2+1);
    addUnion(l,r,unia,mid+1,rx,x*2+2);
  }

  void addUnion(ll l, ll r, Union unia){
    addUnion(l,r,unia,0,ss-1,0);
  }
  // [l...r]
  void addOffy(ll l, ll r, TurnOff &off, ll lx, ll rx, ll x){
    dbg(l,r,lx,rx,x);
    if(l <= lx && rx <= r){
      cout << "addingoff";
      dbg(l,r,lx,rx,x);
      offy[x].pb(off);
      return;
    } else if(r < lx || rx < l) return;
    ll mid = (lx+rx)/2;
    addOffy(l,r,off,lx,mid,x*2+1);
    addOffy(l,r,off,mid+1,rx,x*2+2);
  }

  void addOffy(ll l, ll r, TurnOff off){
    addOffy(l,r,off,0,ss-1,0);
  }
};

SegTree segtree;
DSU_with_rollback dsu;

bool is_leaf(ll x){
  return x >= segtree.ss-1; // nie wiem czy to na pewno poprawne
}

bool okej(Binsearch &binsearch){
  ll a = binsearch.farma;
  dbg(binsearch.farma);
  cout << "parent:\n";
  for(ll i = 0; i <= dsu.parent.size(); i++){
    cout << dsu.parent[i] << " ";
  }
  cout << endl;
  cout << "sajz:\n";
  for(ll i = 0; i <= dsu.sajz.size(); i++){
    cout << dsu.sajz[i] << " ";
  }
  cout << endl;
  cout << "turned_off:\n";
  for(ll i = 0; i <= dsu.turned_off.size(); i++){
    cout << dsu.turned_off[i] << " ";
  }
  cout << endl;
  a = dsu.findSet(a);
  return dsu.sajz[a] > dsu.turned_off[a];
}

void dfs(ll x){
  dbg(x, segtree.unie[x].size(), segtree.offy[x].size());
  for(Union unia : segtree.unie[x]){
    dsu.unionSets(unia.a, unia.b);
  }
  for(TurnOff off : segtree.offy[x]){
    dsu.turn_off(off.a);
  }
  if(is_leaf(x)){
    ll index = x-(segtree.ss-1);
    if(index <= q){
      dbg(x, index);
      for(Binsearch binsearch : bin[index]){
        dbg(binsearch.l, binsearch.mid, binsearch.r, binsearch.farma);
        if(okej(binsearch)){
          binsearch = Binsearch(binsearch.mid, binsearch.r, binsearch.farma);
          cout << "ok\n";
        } else{
          binsearch = Binsearch(binsearch.l, binsearch.mid-1, binsearch.farma);
          cout << "not ok\n";
        }
        if(binsearch.l >= binsearch.r){
          wyniki[binsearch.farma] = binsearch.r;
          ilosc_binsearchy--;
          continue;
        }
        bin[binsearch.mid].pb(binsearch);
      }
      bin[index].clear();
      bin[index].shrink_to_fit();
    }
  } else{
    dfs(x*2+1);
    dfs(x*2+2);
  }
  for(ll i = 0; i < segtree.unie[x].size(); i++) dsu.rollbackUnion();
  for(ll i = 0; i < segtree.offy[x].size(); i++) dsu.rollbackTurnOff();
}
void solve()
{
  cin >> n >> q;
  segtree.resize(q);
  dsu.resize(n);
  input.resize(q);
  for(ll i = 0; i < q; i++){
    cin >> c;
    if(c == 'A'){
      cin >> d >> e;
      adds.pb({d,e,i});
    } else if(c == 'R'){
      cin >> d;
      segtree.addUnion(adds[d-1][2], i-1, Union(adds[d-1][0], adds[d-1][1]));
    } else{
      cin >> d;
      segtree.addOffy(i, q, TurnOff(d));
    }
  }
  for(ll farma = 1; farma <= n; farma++) bin[(q/2)].pb(Binsearch(0, q, farma));
  ilosc_binsearchy = n;
  ll cnt = 0;
  while(ilosc_binsearchy > 0 && cnt++ < 1) dfs(0);

  for(ll farma = 1; farma <= n; farma++) cout << wyniki[farma] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

 
}