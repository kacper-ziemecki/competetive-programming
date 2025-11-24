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

// drzewo przedzialowe punkt-przedział
// const ll ss = 1 << 19;
// vector<ll> nodes(ss*2);


// void add1(int a, int v){
//   a += ss;
//   while(a > 0){
//     nodes[a] += v;
//     a <<= 1;
//   }
// }
// ll get1(int a, int b){
//   a += ss-1;
//   b += ss+1;
//   ll res = 0;
//   while(a/2 != b/2){
//     if(a%2 == 0) res += nodes[a+1];
//     if(b%2 == 1) res += nodes[b-1];
//     a >>= 1; b >>= 1;
//   }
//   return res;
// }

// drzewo przedzialowe przedzial-punkt

const ll ss = 1 << 19;
vector<ll> nodes(ss*2);

void add(ll a, ll b, ll v){
  a += ss-1;
  b += ss+1;
  while(a/2 != b/2){
    if(a%2 == 0) nodes[a+1] += v;
    if(b%2 == 1) nodes[b-1] += v;
    a >>= 1; b >>= 1;
  }
}

ll get(ll a){
  a += ss;
  ll res = 0;
  while(a > 0){
    res += nodes[a];
    a <<= 1;
  }
  return res;

}

// mega krotki kod
// void upd1(int a,int b){
//     for(a+=SS;a>0;a/=2) seg[a]=max(seg[a],b);
// }
// int qr1(int a,int b){
//     int res=0;
//     for(a+=SS-1,b+=SS+1;a/2!=b/2;a/=2,b/=2){
//         if(a%2==0) res=max(res,seg[a+1]);
//         if(b%2) res=max(res,seg[b-1]);
//     }
//     return res;
// }

// przedzial-punkt
struct SegTree{
  vector<ll> nodes;
  ll length;
  SegTree(){}
  SegTree(ll n){
    length = 1;
    while(length <= n) length <<= 1;
    nodes.resize(length<<1);
  }
  void clear(){
    length = 0;
    nodes.clear();
    nodes.shrink_to_fit();
  }
  void resize(ll n){
    length = 1;
    while(length <= n) length <<= 1;
    nodes.resize(length<<1);
  }
  //[l...r]
  void add(ll l, ll r, ll v, ll lx, ll rx, ll x){
    if(l <= lx && rx <= r){
      nodes[x] += v;
      return;
    } else if(r < lx || rx < l) return;
    ll mid = (lx+rx)/2;
    add(l,r,v,lx,mid,x*2);
    add(l,r,v,mid+1,rx,x*2+1);
  }

  void add(ll l, ll r, ll v){
    if(l > r){
      add(1, r, v, 1, length, 1);
      add(l, length, v, 1, length, 1);
    } else{
      add(l, r, v, 1, length, 1);
    }
  }
  ll get(ll a, ll lx, ll rx, ll x){
    if(a < lx || rx < a) return 0;
    if(rx-lx == 0) return nodes[x];
    ll mid = (lx+rx)/2;
    return nodes[x] + get(a,lx,mid,x*2) + get(a,mid+1,rx,x*2+1);
  }

  ll get(ll a){
    return get(a, 1, length, 1);
  }
};

struct Binsearch{
  ll l,mid,r,panstwo;
  Binsearch(ll _l, ll _r, ll _panstwo){
    l = _l;
    r = _r;
    panstwo = _panstwo;
    mid = (l+r)/2;
  }
};

const ll maxLiczba = 3e5+1;
ll wyniki[maxLiczba], wlasciciele_sektorow[maxLiczba], ilosc_potrzebnych_probek[maxLiczba], queries[maxLiczba][3];
vector<ll> sektory_panstw[maxLiczba];
vector<Binsearch> bin[maxLiczba];
ll liczba_panstw, liczba_sektorow, k, ilosc_binsearchy;
SegTree segtree;

bool okej(Binsearch binsearch){
  ll zebrane = 0;
  for(auto sektor : sektory_panstw[binsearch.panstwo]) zebrane += segtree.get(sektor);
  return zebrane >= ilosc_potrzebnych_probek[binsearch.panstwo];
  
}

void solve()
{
  cin >> liczba_panstw >> liczba_sektorow;
  for(ll i = 0; i < liczba_sektorow; i++) cin >> wlasciciele_sektorow[i];
  for(ll i = 1; i <= liczba_panstw; i++) cin >> ilosc_potrzebnych_probek[i];
  for(ll i = 0; i < liczba_sektorow; i++) sektory_panstw[wlasciciele_sektorow[i]].pb(i+1);
  cin >> k;
  ilosc_binsearchy = liczba_panstw;
  for(ll panstwo = 1; panstwo <= ilosc_binsearchy; panstwo++) bin[(k-1)/2].pb(Binsearch(0, k-1, panstwo));

  for(ll i = 0; i < k; i++){
    for(ll j = 0; j < 3; j++){
      cin >> queries[i][j];
    }
  }

  while(ilosc_binsearchy > 0){
    segtree.clear();
    segtree.resize(liczba_sektorow);
    for(ll i = 0; i < k; i++){
      segtree.add(queries[i][0], queries[i][1], queries[i][2]);
      for(auto binsearch : bin[i]){
        if(okej(binsearch)){
          binsearch = Binsearch(binsearch.l, binsearch.mid, binsearch.panstwo);
          
        } else{
          binsearch = Binsearch(binsearch.mid+1, binsearch.r, binsearch.panstwo);
        }
        if(binsearch.l >= binsearch.r){
          ilosc_binsearchy--;
          wyniki[binsearch.panstwo] = binsearch.r;
          continue;
        }
        bin[binsearch.mid].pb(binsearch);
      }
      bin[i].clear();
      bin[i].shrink_to_fit();
    }
  }

  segtree.clear();
  segtree.resize(liczba_sektorow);
  for(ll i = 0; i < k; i++) segtree.add(queries[i][0], queries[i][1], queries[i][2]);
  
  for(ll panstwo = 1; panstwo <= liczba_panstw; panstwo++){
    if(wyniki[panstwo] == k-1 && !okej(Binsearch(k-1,k-1,panstwo))){
      cout << "NIE\n";
    } else{
      cout << wyniki[panstwo]+1 << endl;
    }
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}