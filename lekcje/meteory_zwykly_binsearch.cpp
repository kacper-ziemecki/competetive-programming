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

// przedzial-punkt
struct SegTree{
  vector<ll> nodes;
  ll length;
  SegTree(ll n){
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

const ll maxLiczba = 3e5+1;
ll wlasciciele_sektorow[maxLiczba], ilosc_potrzebnych_probek[maxLiczba], queries[maxLiczba][3];
vector<ll> sektory_panstw[maxLiczba];
ll liczba_panstw, liczba_sektorow, k;

bool okej(ll mid, ll panstwo){
  SegTree segtree(liczba_sektorow);
  for(ll i = 0; i <= mid; i++) segtree.add(queries[i][0], queries[i][1], queries[i][2]);
  ll zebrane = 0;
  for(auto sektor : sektory_panstw[panstwo]) zebrane += segtree.get(sektor);
  return zebrane >= ilosc_potrzebnych_probek[panstwo];
}

void solve()
{
  cin >> liczba_panstw >> liczba_sektorow;
  for(ll i = 0; i < liczba_sektorow; i++) cin >> wlasciciele_sektorow[i];
  for(ll i = 1; i <= liczba_panstw; i++) cin >> ilosc_potrzebnych_probek[i];
  for(ll i = 0; i < liczba_sektorow; i++) sektory_panstw[wlasciciele_sektorow[i]].pb(i+1);
  cin >> k;
  for(ll i = 0; i < k; i++){
    for(ll j = 0; j < 3; j++){
      cin >> queries[i][j];
    }
  }

  for(ll panstwo = 1; panstwo <= liczba_panstw; panstwo++){
    ll left = 0, right = k-1;
    while(left < right){
      ll mid = (left+right)/2;
      if(okej(mid, panstwo)) right = mid;
      else left = mid+1;
    }
    if(right == k-1 && !okej(right, panstwo)) cout << "NIE\n";
    else cout << right+1 << endl;
  }
}
                          

// Time complexity: O(n * log(k) * k * log(m))
// nie potrzebny jest log(k) bo i tak w najgorszym przypadku zrobimy O(m log m) dla każdej operacji
// czyli możemy stworzyć algorytm bez binsearcha z czasem O(n * k * log(m))
// ale to dalej jest za wolno i my tylko usunelismy jednego log(k) co tak naprawde jest bardzo malo
// za to mozemy powrocic do poprzedniej wersji i sprobowac zmienic "n" na log(n)
// 1. mozemy miec tablice ktora bedzie przechowywała stan wyszukiwania binarnego dla kazdego panstwa {left, middle, right}
//    tych wartosci bedzie na poczotku "n" i ich ilosc bedzie malec z czasem jak obliczymy wuszykiwania binarne poszczegolnych panstw
// 2. bedziemy mieli globalne wyszukiwanie binarne które po prostu za kazdym wywowałaniem bedzie przechodzilo przez tą naszą liste
//    i bedzie pokolei obliczalo nastepny krok w wyszukiwaniu binarnym konkretnego panstwa
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}