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

int n,ilosc_okien;
const int N = 501;
const int MX_OKNA = 4*N;
const int MOD = 1e9+7;
pair<int,int> okienka[N], uporzodkowane_okienka[MX_OKNA];
set<int> pozodki;
vector<int> lista;
ull dp[N][MX_OKNA], pref2D[N][MX_OKNA], pref1D[N][1001];
int ile_przed[MX_OKNA];

bool zawiera(int l1, int r1, int l2, int r2){
  if(l1 <= l2 && r2 <= r1) return true;
  return false;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> okienka[i].first >> okienka[i].second;
    pozodki.emplace(okienka[i].first);
    pozodki.emplace(okienka[i].second);
  }  
  ilosc_okien = pozodki.size()-1;
  for(auto el : pozodki) lista.pb(el);
  int j = 0;
  for(int i = 0; i < lista.size(); i++){
    uporzodkowane_okienka[j] = make_pair(lista[i], lista[i]);
    j++;
    if(i != lista.size()-1 && lista[i+1]-1 != lista[i]){
      ll lewo = lista[i];
      while((lista[i+1]-1) - lewo > 1000){
        uporzodkowane_okienka[j] = make_pair(lewo, lewo+1000);
        j++;
        lewo += 1000;
      }
      if(lewo!=(lista[i+1]-1)){
        uporzodkowane_okienka[j] = make_pair(lista[i], lista[i+1]-1);
        j++;
      }  
    }
  }
  ull res = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < MX_OKNA; j++){
      // dbg(uporzodkowane_okienka[j].second, uporzodkowane_okienka[j].first);
      if(zawiera(okienka[i].first,okienka[i].second,uporzodkowane_okienka[j].first,uporzodkowane_okienka[j].second)){
        //obliczamy teraz dp[i][j]
        ull wielkosc_okna = uporzodkowane_okienka[j].second - uporzodkowane_okienka[j].first + 1;
        //1. bierzemy tylko siebie i nic przed
        dp[i][j] = wielkosc_okna % MOD;
        //2. bierzemy wszystkie mozliwosci z okienek ponizej
        if(i-1 >= 0 && j-1 >= 0) dp[i][j] = (dp[i][j] + pref2D[i-1][j-1]) % MOD;
        //3. bierzemy wszystkie mozliwosci z aktualnego okienka
        // pref1D nie moze uwzgledniac najwyzszego
        dp[i][j] = (dp[i][j] + pref1D[ile_przed[j]][wielkosc_okna-1]) % MOD;
        // for(int k = 0; k < )
        ile_przed[j]++;
        res = (res + dp[i][j]) % MOD;
      }

      pref2D[i][j] = (j-1 < 0 ? 0 : pref2D[i][j-1]) % MOD + (i-1 < 0 ? 0 : pref2D[i-1][j]) % MOD - (i-1 < 0 || j-1 < 0 ? 0 : pref2D[i-1][j-1]) % MOD + dp[i][j] % MOD + MOD % MOD;  

    }
  }
  cout << res << endl;
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

  //precalculate pref1D - roznozedne okienka
  for(int i = 0; i < N; i++){ //ilosc przed
    for(int j = 1; j < 1001; j++){ //dlugosc okna
      pref1D[i][j] = 1 + (i-1 < 0 ? 0 : pref1D[i-1][j]) % MOD + (j-1 < 0 ? 0 : pref1D[i][j-1]) % MOD;
    }
  }
  
  solve();
}