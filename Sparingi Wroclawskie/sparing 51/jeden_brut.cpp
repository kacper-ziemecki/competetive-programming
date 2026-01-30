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

set<vector<pair<int,int>>> res;
int n,m;
vector<string> lista;
vector<vector<bool>> vis;
vector<ll> dirI = {-1,0,1,0}, dirJ = {0,1,0,-1};

bool in_bounds(ll i, ll j){
  if(i < 0 || j < 0 || i >= n || j >= m) return false;
  return true;
}

bool checker(int i, int j){
  vis[i][j] = true;
  if(i == n-1 && j == m-1) return true;
  bool res = false;
  for(int k = 0; k < 4; k++){
    int i1 = i+dirI[k], j1 = j+dirJ[k];
    if(in_bounds(i1,j1) && lista[i1][j1] == '.' && !vis[i1][j1]) res = res | checker(i1,j1);
  }
  return res;
}

void solve(){
  cin >> n >> m;
  lista.resize(n);
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i1 = 0; i1 < n; i1++){
    for(int j1 = 0; j1 < m; j1++){
      if(lista[i1][j1] != 'X') continue;
      for(int i2 = 0; i2 < n; i2++){
        for(int j2 = 0; j2 < m; j2++){
          if(lista[i2][j2] != 'X') continue;
          if(i1 == i2 && j1 == j2) continue;
          lista[i1][j1] = '.';
          lista[i2][j2] = '.';
          vis.assign(n, vector<bool>(m, false));
          if(checker(0,0)){
            vector<pair<int,int>> tmp = {make_pair(i1,j1),make_pair(i2,j2)};
            sort(tmp.begin(), tmp.end());
            res.emplace(tmp);
          }
          lista[i1][j1] = 'X';
          lista[i2][j2] = 'X';
        }
      }
    }
  }  
  cout << res.size() << endl;
  for(auto el : res){
    cout << el[0].first << "," << el[0].second << " | " << el[1].first << "," << el[1].second << endl;
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