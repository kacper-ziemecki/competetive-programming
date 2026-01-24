#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct DSU{
  vector<ll> p,sajz,ilosc_od_start;
  void resize(ll n){
    sajz.assign(n+1, 1);
    p.resize(n+1);
    ilosc_od_start.assign(n+1, 0);
    for(ll i = 0 ; i < n+1; i++) p[i] = i;
  }
  ll findSet(ll a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSets(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool isConnected(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    return a == b;
  }
};

ll n,m,ilosc_x,res;
vector<string> lista;
vector<vector<bool>> od_start, do_finish;
vector<ll> dirI = {-1,0,1,0}, dirJ = {0,1,0,-1};
DSU dsu;

bool in_bounds(ll i, ll j){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}

void calc_od_start(ll i, ll j){
  od_start[i][j] = true;
  for(ll k = 0; k < 4; k++){
    ll i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && od_start[i1][j1]) continue;
    if(in_bounds(i1,j1) && lista[i1][j1] == '.') calc_od_start(i1,j1);
    if(in_bounds(i1,j1) && lista[i1][j1] == 'X') od_start[i1][j1] = true;
  }
}

void calc_do_finish(ll i, ll j){
  do_finish[i][j] = true;
  for(ll k = 0; k < 4; k++){
    ll i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && do_finish[i1][j1]) continue;
    if(in_bounds(i1,j1) && lista[i1][j1] == '.') calc_do_finish(i1,j1);
    if(in_bounds(i1,j1) && lista[i1][j1] == 'X') do_finish[i1][j1] = true;
  }
}

void to_which_connected(ll i, ll j){
  for(ll k = 0; k < 4; k++){
    ll i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && !dsu.isConnected(i1*m+j1, i*m+j) && !(do_finish[i1][j1] && od_start[i1][j1])){
      dsu.unionSets(i1*m+j1, i*m+j);
      if(od_start[i1][j1] && lista[i1][j1] == 'X') dsu.ilosc_od_start[dsu.findSet(i*m+j)]++;
      if(lista[i1][j1] == '.') to_which_connected(i1,j1);
    }
  }
}

void solve(){
  cin >> n >> m;
  lista.resize(n);
  dsu.resize(n*m);
  od_start.assign(n, vector<bool>(m, false));
  do_finish.assign(n, vector<bool>(m, false));
  for(ll i = 0; i < n; i++) cin >> lista[i];
  calc_od_start(0,0);
  calc_do_finish(n-1,m-1);
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(lista[i][j] == 'X') ilosc_x++;
    }
  }
  if(od_start[n-1][m-1]){
    cout << ilosc_x * (ilosc_x-1) / 2 << endl;
    return;
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(do_finish[i][j] && od_start[i][j] && (lista[i][j] == 'X')){
        // dbg(i,j,ilosc_x-1);
        res += ilosc_x-1;
      } 
      else if(do_finish[i][j] && !od_start[i][j] && (lista[i][j] == 'X')){
        // dbg(i,j);
        map<ll, ll> mp;
        for(ll k = 0; k < 4; k++){
          ll i1 = i+dirI[k], j1 = j+dirJ[k];
          if(in_bounds(i1,j1) && lista[i1][j1] == '.'){
            to_which_connected(i1,j1);
            mp[dsu.findSet(i1*m+j1)] = dsu.ilosc_od_start[dsu.findSet(i1*m+j1)];
            // dbg(i1,j1,dsu.ilosc_od_start[dsu.findSet(i1*m+j1)]);
          }
          //przypadek kiedy lista[i1][j1] == 'X' i tez jest od_start[i1][j1] tylko
          //zakodowany na dole
        }
        for(ll k = 0; k < 4; k++){
          ll i1 = i+dirI[k], j1 = j+dirJ[k];
          // dbg(i1,j1,mp.count(dsu.findSet(i1*m+j1)));
          if(in_bounds(i1,j1) && (lista[i1][j1] == 'X') && (!do_finish[i1][j1]) && od_start[i1][j1] && (mp.count(dsu.findSet(i1*m+j1)) == 0)){
            // dbg("dziala");
            mp[dsu.findSet(i1*m+j1)] = 1;
          }
        }
        for(auto el : mp){
          // dbg(el.first,el.second);
          res += el.second;
        }
        // dbg(i,j,dsu.ilosc_od_start[dsu.findSet(i*m+j)]);
        // res += dsu.ilosc_od_start[dsu.findSet(i*m+j)];
      }
    }
  }
  cout << res << endl;
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