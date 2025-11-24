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

struct BinSearch{
  ll l,mid,r,farm;
  BinSearch(ll _l, ll _r, ll _farm){
    l = _l;
    r = _r;
    mid = (l+r+1)/2;
    farm = _farm;
  }
};
struct DSU{
  vector<ll> p, sajz, num_active;
  DSU(){}
  DSU(ll n){
    p.resize(n+1);
    sajz.assign(n+1, 1);
    num_active.assign(n+1, 0);
    for(ll i = 0; i <= n; i++) p[i] = i;
  }
  ll findSet(ll a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSet(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
    num_active[a] += num_active[b];
  }
  void activate(ll a){
    a = findSet(a);
    num_active[a]++;
  }
  bool is_active(ll a){
    a = findSet(a);
    return num_active[a] > 0;
  }
  void clear(){
    p.clear(); sajz.clear(); num_active.clear();
  }
  void resize(ll n){
    p.resize(n+1);
    sajz.assign(n+1, 1);
    num_active.assign(n+1, 0);
    for(ll i = 0; i <= n; i++) p[i] = i;
  }
};
char a;
ll b,c;
ll n,q;
const ll maxLiczba = 2e5+1;
vector<pair<ll,ll>> adds;
vector<vector<ll>> input;
bool activated[maxLiczba], notRemoved[maxLiczba];
vector<BinSearch> bin[maxLiczba];
ll result[maxLiczba];
ll num_binsearches;
DSU dsu;

void computeBinarySearches(ll mid){
  // dbg(mid);
  for(BinSearch binsearch : bin[mid]){
    if(dsu.is_active(binsearch.farm)){
      binsearch = BinSearch(binsearch.mid, binsearch.r, binsearch.farm);
    } else{
      binsearch = BinSearch(binsearch.l, binsearch.mid-1, binsearch.farm);
    }
    if(binsearch.r == binsearch.l){
      num_binsearches--;
      result[binsearch.farm] = binsearch.mid;
    } else{
      // dbg(binsearch.mid);
      bin[binsearch.mid].pb(binsearch);
    }
  }
  bin[mid].clear();
  bin[mid].shrink_to_fit();
}
void solve()
{
  cin >> n >> q;
  for(ll i = 0; i < maxLiczba; i++){ activated[i] = true; notRemoved[i]=true;}
  num_binsearches = n;
  for(ll i = 0; i < q; i++){
    cin >> a;
    if(a == 'A'){
      cin >> b >> c;
      input.pb({1,b,c});
      adds.pb({b,c});
    } else if(a == 'D'){
      cin >> b;
      input.pb({2,b});
      activated[b] = false;
    } else{
      cin >> b;
      input.pb({3,b});
      notRemoved[b-1]=false;
    }
  }
  for(ll i = 1; i <= n; i++) bin[(q/2)].pb(BinSearch(0, q, i));

  while(num_binsearches){
    dsu.clear();
    dsu.resize(n);
    for(ll i = 0; i < adds.size(); i++){
      if(notRemoved[i]) dsu.unionSet(adds[i].first, adds[i].second);
    }
    for(ll i = 1; i <= n; i++){
      // cout << activated[i] << " ";
      if(activated[i]) dsu.activate(i);
    }
    // cout << endl;

    for(ll i = q; i >= 0; i--){
      if(i != q){      
        // dbg(input[i][0]);
        if(input[i][0] == 2){
          dsu.activate(input[i][1]);
        } else if(input[i][0] == 3){
          dsu.unionSet(adds[input[i][1]-1].first, adds[input[i][1]-1].second);
        } 
      }
      // dbg(i);
      // cout << "p:\n";
      // for(ll farm = 1; farm <= n; farm++) cout << dsu.p[farm] << " ";
      // cout << endl;
      // cout << "num_active:\n";
      // for(ll farm = 1; farm <= n; farm++) cout << dsu.num_active[farm] << " ";
      // cout << endl;
      // cout << "sajz:\n";
      // for(ll farm = 1; farm <= n; farm++) cout << dsu.sajz[farm] << " ";
      // cout << endl;
      computeBinarySearches(i);
    }
  }
  for(ll i = 1; i <= n; i++) cout << result[i] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

 
}