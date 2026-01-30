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
  vector<int> p,sajz,ilosc_od_start;
  void resize(int n){
    sajz.assign(n+1, 1);
    p.resize(n+1);
    ilosc_od_start.assign(n+1, 0);
    for(int i = 0 ; i < n+1; i++) p[i] = i;
  }
  int findSet(int a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
    ilosc_od_start[a] += ilosc_od_start[b];
  }
  bool isConnected(int a, int b){
    a = findSet(a);
    b = findSet(b);
    return a == b;
  }
};

int n,m,ilosc_x,res,oba_dostep;
vector<string> lista;
vector<vector<bool>> od_start, do_finish;
vector<int> dirI = {-1,0,1,0}, dirJ = {0,1,0,-1};
vector<vector<int>> vis;
vector<pair<int,int>> razem;
DSU dsu;

bool in_bounds(int i, int j){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}

void calc_od_start(int i, int j){
  od_start[i][j] = true;
  for(int k = 0; k < 4; k++){
    int i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && od_start[i1][j1]) continue;
    if(in_bounds(i1,j1) && lista[i1][j1] == '.') calc_od_start(i1,j1);
    if(in_bounds(i1,j1) && lista[i1][j1] == 'X') od_start[i1][j1] = true;
  }
}

void calc_do_finish(int i, int j){
  do_finish[i][j] = true;
  for(int k = 0; k < 4; k++){
    int i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && do_finish[i1][j1]) continue;
    if(in_bounds(i1,j1) && lista[i1][j1] == '.') calc_do_finish(i1,j1);
    if(in_bounds(i1,j1) && lista[i1][j1] == 'X') do_finish[i1][j1] = true;
  }
}

void to_which_connected(int i, int j, int c){
  if(vis[i][j] != -1) return;
  vis[i][j] = c;
  // dbg("to which",i,j);
  for(int k = 0; k < 4; k++){
    int i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && !dsu.isConnected(i1*m+j1, i*m+j) && !(do_finish[i1][j1] && od_start[i1][j1])){
      // dbg("union",i,j,i1,j1);
      if(od_start[i1][j1] && lista[i1][j1] == 'X' && vis[i1][j1] != c){
        if(vis[i1][j1] != -1) razem.pb(make_pair(vis[i1][j1], c));
        vis[i1][j1] = c;
        // dbg(i1,j1,c);
        dsu.ilosc_od_start[dsu.findSet(i*m+j)]++;
      }
      if(lista[i1][j1] == '.'){
        dsu.unionSets(i1*m+j1, i*m+j);
        to_which_connected(i1,j1,c);
      }
    }
  }
}

void solve(){
  cin >> n >> m;
  lista.resize(n);
  dsu.resize(n*m);
  vis.assign(n, vector<int>(m,-1));
  od_start.assign(n, vector<bool>(m, false));
  do_finish.assign(n, vector<bool>(m, false));
  for(int i = 0; i < n; i++) cin >> lista[i];
  calc_od_start(0,0);
  calc_do_finish(n-1,m-1);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(lista[i][j] == 'X') ilosc_x++;
    }
  }
  if(od_start[n-1][m-1]){
    cout << ilosc_x * (ilosc_x-1) / 2 << endl;
    return;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(do_finish[i][j] && od_start[i][j] && (lista[i][j] == 'X')){
        // dbg(i,j,ilosc_x-1-oba_dostep);
        res += ilosc_x-1-oba_dostep;
        oba_dostep++;
      } 
      else if(do_finish[i][j] && !od_start[i][j] && (lista[i][j] == 'X')){
        // dbg(i,j);
        map<int, int> mp;
        razem.clear();
        for(int k = 0; k < 4; k++){
          int i1 = i+dirI[k], j1 = j+dirJ[k];
          if(in_bounds(i1,j1) && lista[i1][j1] == '.'){
            to_which_connected(i1,j1,i1*m+j1);
            // dbg(i1,j1,dsu.ilosc_od_start[dsu.findSet(i1*m+j1)]);
            mp[dsu.findSet(i1*m+j1)] = dsu.ilosc_od_start[dsu.findSet(i1*m+j1)];
          }
          //przypadek kiedy lista[i1][j1] == 'X' i tez jest od_start[i1][j1] tylko
          //zakodowany na dole
        }
        for(auto el : razem){
          el.first  = dsu.findSet(el.first);
          el.second = dsu.findSet(el.second);
          if(mp.count(el.first) && mp.count(el.second)) res--;
        }
        for(int k = 0; k < 4; k++){
          int i1 = i+dirI[k], j1 = j+dirJ[k];
          // dbg(i,j,i1,j1,mp.count(dsu.findSet(i1*m+j1)));
          if(in_bounds(i1,j1) && (lista[i1][j1] == 'X') && (!do_finish[i1][j1]) && od_start[i1][j1]){
            // dbg("dziala");
            bool mozna_dojsc = false;
            for(int r = 0; r < 4; r++){
              int i2 = i1+dirI[r], j2 = j1+dirJ[r];
              if(in_bounds(i2,j2) && (lista[i2][j2] == '.') && mp.count(dsu.findSet(i2*m+j2))){
                mozna_dojsc = true;
              }
            }
            if(!mozna_dojsc){
              // dbg("+");
              mp[dsu.findSet(i1*m+j1)] = 1;
            }
          }
        }
        // if(in_bounds(i-1,j-1) && lista[i-1][j-1] == 'X' && !do_finish[i-1][j-1] && od_start[i-1][j-1] && lista[i-1][j] == '.' && lista[i][j-1] == '.' && (dsu.findSet((i-1)*m+j) != dsu.findSet(i*m+(j-1)))){
        //   res--;
        // }
        // if(in_bounds(i-1,j+1) && lista[i-1][j+1] == 'X' && !do_finish[i-1][j+1] && od_start[i-1][j+1] && lista[i-1][j] == '.' && lista[i][j+1] == '.' && (dsu.findSet((i-1)*m+j) != dsu.findSet(i*m+(j+1)))){
        //   res--;
        // }
        // if(in_bounds(i+1,j+1) && lista[i+1][j+1] == 'X' && !do_finish[i+1][j+1] && od_start[i+1][j+1] && lista[i][j+1] == '.' && lista[i+1][j] == '.' && (dsu.findSet((i+1)*m+j) != dsu.findSet(i*m+(j+1)))){
        //   res--;
        // }
        // if(in_bounds(i+1,j-1) && lista[i+1][j-1] == 'X' && !do_finish[i+1][j-1] && od_start[i+1][j-1] && lista[i][j-1] == '.' && lista[i+1][j] == '.' && (dsu.findSet((i+1)*m+j) != dsu.findSet(i*m+(j-1)))){
        //   res--;
        // }
        for(auto el : mp){
          // dbg(i,j,el.first,el.second);
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