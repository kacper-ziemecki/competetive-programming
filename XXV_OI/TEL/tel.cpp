#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
char c;
int x,y,z,s,a,x1,x2;
const int maxn = 300000+1;
pair<int,int> lista[maxn];

struct SegTree{
  vector<int> suma;
  vector<vector<pair<int,int>>> lazy;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    suma.assign(ss<<1, 0);
    lazy.assign(ss<<1, vector<pair<int,int>>(2, {0,0})); 
    //pierwszy element to lewo drugi to prawo  (1 ---->), (0 <----)
    //first - sila poczotkowa, second - upadek co 1m
  }
  void propagate(int l, int r, int x, int kierunek){
    int a1 = (kierunek == 1 ? lazy[x][kierunek].first - l*lazy[x][kierunek].second : lazy[x][kierunek].first - (n+1-r)*lazy[x][kierunek].second);
    int an = (kierunek == 1 ? lazy[x][kierunek].first - r*lazy[x][kierunek].second : lazy[x][kierunek].first - (n+1-l)*lazy[x][kierunek].second);
    // dbg(a1,an);
    int s = (a1+an)*(r-l+1)/2;
    suma[x] += s;
    if((x*2+1) < (ss<<1)){
      lazy[x*2+1][kierunek].first += lazy[x][kierunek].first;
      lazy[x*2+1][kierunek].second += lazy[x][kierunek].second;
    }
    if((x*2+2) < (ss<<1)){
      lazy[x*2+2][kierunek].first += lazy[x][kierunek].first;
      lazy[x*2+2][kierunek].second += lazy[x][kierunek].second;
    }
    lazy[x][kierunek] = {0,0};
  }
  void set(int l, int r, pair<int,int> a, int x, int lx, int rx, int kierunek){
    // dbg(lx,rx);
    propagate(lx,rx,x,kierunek);
    if(l <= lx && rx <= r){
      // dbg("ustawienie", lx,rx);
      lazy[x][kierunek].first += a.first;
      lazy[x][kierunek].second += a.second;
      propagate(lx,rx,x,kierunek);
      // dbg(a.first,a.second);
      // dbg(suma[x]);
      return;
    }
    if(rx < l || lx > r) return;

    int mid = (lx+rx)/2;
    set(l,r,a,2*x+1,lx,mid,kierunek);
    set(l,r,a,2*x+2,mid+1,rx,kierunek);
  }
  void set(int l, int r, pair<int,int> a, int kierunek){ // (1 ---->), (0 <----)
    set(l,r,a,0,1,ss,kierunek);
  }

  int get(int l, int r, int x, int lx, int rx){
    propagate(lx,rx,x,1);
    propagate(lx,rx,x,0);
    if(l <= lx && rx <= r){
      // dbg(lx,rx,suma[x]);
      return suma[x];
    }
    if(rx < l || lx > r) return 0;

    int mid = (lx+rx)/2;
    return get(l,r,2*x+1,lx,mid) + get(l,r,2*x+2,mid+1,rx);
  }

  int get(int l, int r){
    return get(l,r,0,1,ss);
  }
};

void solve(){
  cin >> n >> m;
  SegTree segtree(n+1);
  for(int i = 0; i < m; i++){
    cin >> c;
    if(c == 'P'){
      cin >> x >> s >> a;
      lista[x] = make_pair(s,a);
      pair<int,int> prawo = {x*a+s, a}, lewo = {(n+1-x)*a+s, a};
      int l = max(1,x - ((s+a-1)/a)+1);
      int r = min(n,x + ((s+a-1)/a)-1);
      segtree.set(x, r, prawo, 1);
      if(x != r) segtree.set(l, x-1, lewo, 0);
      //  dbg(l,r);
      // dbg(prawo.first,prawo.second);
      // dbg(lewo.first,lewo.second);
      // for(auto el : segtree.suma) cout << el << ' ';
      // cout << endl;
    } else if(c == 'U'){
      cin >> x;
      s = lista[x].first;
      a = lista[x].second;
      pair<int,int> prawo = {-(x*a+s), -a}, lewo = {-((n+1-x)*a+s), -a};
      int l = max(1,x - ((s+a-1)/a)+1);
      int r = min(n,x + ((s+a-1)/a)-1);
      segtree.set(x, r, prawo, 1);
      if(x != r) segtree.set(l, x-1, lewo, 0);
    } else{
      cin >> x1 >> x2;
      cout << segtree.get(x1,x2)/(x2-x1+1) << endl;
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