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

int n;
const int MX = 2503;
const int N = 250001;
pair<int,int> lista[N];
bool grid[MX][MX];
int pref[MX][MX];
int gora[MX], lewo[MX];
int dul[MX], prawo[MX];

void solve(){
  cin >> n;

  for(int i = 0; i < MX; i++){
    gora[i] = MX-1;
    lewo[i] = MX-1;
    dul[i] = 0;
    prawo[i] = 0;
  }
  for(int i = 0; i < n; i++){
    cin >> lista[i].first >> lista[i].second;
  }
  for(int i = 0; i < n; i++){
    grid[lista[i].first][lista[i].second] = true;
  }
  for(int i = 0; i < MX; i++){
    for(int j = 0; j < MX; j++){
      pref[i][j] = grid[i][j] + (i-1 < 0 ? 0 : pref[i-1][j]) + (j-1 < 0 ? 0 : pref[i][j-1]) - (i-1 < 0 || j-1 < 0 ? 0 : pref[i-1][j-1]);
    }
  }
  for(int i = 0; i < MX; i++){
    for(int j = 0; j < MX; j++){
      if(grid[i][j]){
        gora[j] = min({gora[j],(j-1 < 0 ? MX-1 : gora[j-1]), i});
        lewo[i] = min({lewo[i],(i-1 < 0 ? MX-1 : lewo[i-1]), j});
      } else{
        gora[j] = min(gora[j], (j-1 < 0 ? MX-1 : gora[j-1]));
        lewo[i] = min(lewo[i], (i-1 < 0 ? MX-1 : lewo[i-1]));
      }
    }
  }
  for(int i = MX-1; i >= 0; i--){
    for(int j = MX-1; j >= 0; j--){
      if(grid[i][j]){ 
        dul[j] = max({dul[j],(j+1 >= MX ? 0 : dul[j+1]), i});
        prawo[i] = max({prawo[i],(i+1 >= MX ? 0 : prawo[i+1]), j});
      } else{
        dul[j] = max(dul[j],(j+1 >= MX ? 0 : dul[j+1]));
        prawo[i] = max(prawo[i], (i+1 >= MX ? 0 : prawo[i+1]));
      }
    }
  }
  for(int k = 0; k < n; k++){
    int i = lista[k].first;
    int j = lista[k].second;
    int jedynki_lewo_gora = pref[i-1][j-1];
    int jedynki_prawo_dul = pref[MX-1][MX-1] - pref[MX-1][j] - pref[i][MX-1] + pref[i][j];
    int left = lewo[i-1];
    int right = prawo[i+1];
    int up = gora[j-1]; 
    int down = dul[j+1];
    int trojki_prawo_gora=0, trojki_lewo_dul=0;
    if(!(right <= j || up >= i)) trojki_prawo_gora = pref[up][MX-1] - pref[up][right] - pref[0][MX-1] + pref[0][right];
    if(!(left >= j || down <= i)) trojki_lewo_dul = pref[MX-1][left] - pref[MX-1][0] - pref[down][left] + pref[down][0];

    dbg(i,j);
    dbg(jedynki_lewo_gora, jedynki_prawo_dul);
    dbg(left,right,up,down);
    dbg(trojki_prawo_gora,trojki_lewo_dul);

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