#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,k;
const int maxN = 101;
int poczotek[maxN][maxN], koniec[maxN][maxN];
vector<vector<int>> PoczotekMini((maxN+1)/2, vector<int>((maxN+1)/2)), KoniecMini((maxN+1)/2, vector<int>((maxN+1)/2));
vector<vector<int>> currentMini((maxN+1)/2, vector<int>((maxN+1)/2));
vector<vector<int>> res, koncoweRuchy;
map<vector<vector<int>>, bool> vis; 
vector<int> dirI = {-1,0,1,0}, dirJ = {0,1,0,-1};

void ruchConvert(bool flag, int i1, int j1, int i2, int j2, int king){
  int realIdxI2 = i2 * 2, realIdxJ2 = j2 * 2;
  //Zawsze idziemy do gory i w prawo
  for(int i = i1-1; i >= realIdxI2; i--){
    if(flag){
      res.pb({king, i, j1}); // do gory
    } else{
      koncoweRuchy.pb({king, i, j1}); // do gory
    }
  }
  for(int j = j1-1; j >= realIdxJ2; j--){
    if(flag){
      res.pb({king, realIdxI2, j}); // w lewo
    } else{
      koncoweRuchy.pb({king, realIdxI2, j}); // w lewo
    }
  }
}

void convert(bool flag){
  int idxI = 0, idxJ = 0;
  for(int i = 0; i < n; i+=2){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < 2; k++){
        if(flag && poczotek[i+k][j] != 0){
          dbg(i+k,j,idxI,idxJ,poczotek[i+k][j]);
          PoczotekMini[idxI][idxJ] = poczotek[i+k][j];
          ruchConvert(flag, i+k, j, idxI, idxJ, poczotek[i+k][j]);
          idxJ++;
        } else if(!flag && koniec[i+k][j] != 0){
          KoniecMini[idxI][idxJ] = koniec[i+k][j];
          ruchConvert(flag, i+k, j, idxI, idxJ, koniec[i+k][j]);
          idxJ++;
        }
      }
    }
    idxI++;
    idxJ = 0;
  }
}

bool allPermutations(){
  if(currentMini == KoniecMini) return true;
  if(vis[currentMini]) return false; 
  cout << "Current permutation: " << endl;
  for(int i = 0; i < (n+1)/2; i++){
    for(int j = 0; j < (n+1)/2; j++){
      cout << currentMini[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  vis[currentMini] = true;
  for(int i = 0; i < (n+1)/2; i++){
    for(int j = 0; j < (n+1)/2; j++){
      if(currentMini[i][j] == 0){
        for(int k = 0; k < 4; k++){
          int i1 = i+dirI[k], j1 = j+dirJ[k];
          if(i1 < 0 || j1 < 0 || i1 >= (n+1)/2 || j1 >= (n+1)/2) continue;
          if(currentMini[i1][j1] == 0) continue;
          currentMini[i][j] = currentMini[i1][j1];
          currentMini[i1][j1] = 0;
          if(allPermutations()) return true;
          currentMini[i1][j1] = currentMini[i][j];
          currentMini[i][j] = 0;
        }
      }
    }
  }
  return false;
}

void solve(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> poczotek[i][j];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> koniec[i][j];
  }
  convert(true);
  convert(false);

  for(int i = 0; i < (n+1)/2; i++){
    for(int j = 0; j < (n+1)/2; j++){
      cout << PoczotekMini[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for(int i = 0; i < (n+1)/2; i++){
    for(int j = 0; j < (n+1)/2; j++){
      cout << KoniecMini[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for(auto subRes : res){
    dbg(subRes[0],subRes[1],subRes[2]);
  }
  cout << endl;
  for(auto subKon : koncoweRuchy)
    dbg(subKon[0],subKon[1],subKon[2]);
  cout << endl;
  for(int i = 0; i < (n+1)/2; i++){
    for(int j = 0; j < (n+1)/2; j++) currentMini[i][j] = PoczotekMini[i][j];
  }

  if(allPermutations()){
    cout << "TAK\n";
  } else{
    cout << "NIE\n";
  }
  dbg(vis.size());
  for(auto el : vis){
     for(int i = 0; i < (n+1)/2; i++){
      for(int j = 0; j < (n+1)/2; j++) cout << el.first[i][j] << ' ';
      cout << endl;
    }
    cout << endl;
  }
}
 
int main()
{

  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

} 