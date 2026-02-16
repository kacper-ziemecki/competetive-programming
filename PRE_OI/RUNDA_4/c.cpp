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

const hs prime[] = {5586985605742039601,6889537187409766193};
const int N = 2e5+1;
hs powers_prime[2][N];
hs hash1[2];
hs hash2[2][N];
ll n,k,previous;
const ll MOD = 1e9+7;
string s,t;
vector<vector<ll>> dp;
vector<int> wynikowe_przesuniecia;
ll wynik;

hs przesun(int przesuniecie, int k){
  if(przesuniecie == 0) return hash2[k][n-1];

  hs nowy_hash = hash2[k][n-1]-(hash2[k][przesuniecie-1]*powers_prime[k][n-przesuniecie]);
  nowy_hash = nowy_hash * powers_prime[k][przesuniecie];
  nowy_hash = nowy_hash + hash2[k][przesuniecie-1];

  return nowy_hash;
}

vector<vector<ll>> mnozenie(vector<vector<ll>> a, vector<vector<ll>> b){
  vector<vector<ll>> res(3, vector<ll>(3, 0));
  res[0][0] = ((a[0][0]*b[0][0])%MOD+(a[0][1]*b[1][0])%MOD+(a[0][2]*b[2][0])%MOD)%MOD;
  res[0][1] = ((a[0][0]*b[0][1])%MOD+(a[0][1]*b[1][1])%MOD+(a[0][2]*b[2][1])%MOD%MOD);
  res[0][2] = ((a[0][0]*b[0][2])%MOD+(a[0][1]*b[1][2])%MOD+(a[0][2]*b[2][2])%MOD)%MOD;
  res[1][0] = ((a[1][0]*b[0][0])%MOD+(a[1][1]*b[1][0])%MOD+(a[1][2]*b[2][0])%MOD)%MOD;
  res[1][1] = ((a[1][0]*b[0][1])%MOD+(a[1][1]*b[1][1])%MOD+(a[1][2]*b[2][1])%MOD)%MOD;
  res[1][2] = ((a[1][0]*b[0][2])%MOD+(a[1][1]*b[1][2])%MOD+(a[1][2]*b[2][2])%MOD)%MOD;
  res[2][0] = ((a[2][0]*b[0][0])%MOD+(a[2][1]*b[1][0])%MOD+(a[2][2]*b[2][0])%MOD)%MOD;
  res[2][1] = ((a[2][0]*b[0][1])%MOD+(a[2][1]*b[1][1])%MOD+(a[2][2]*b[2][1])%MOD)%MOD;
  res[2][2] = ((a[2][0]*b[0][2])%MOD+(a[2][1]*b[1][2])%MOD+(a[2][2]*b[2][2])%MOD)%MOD;
  return res;
}

vector<vector<ll>> binpow(vector<vector<ll>> macierz, int b){
  vector<vector<ll>> res = {{1,0,0}, {0,1,0}, {0,0,1}};
  while(b){
    if(b&1) res = mnozenie(res, macierz);
    macierz = mnozenie(macierz,macierz);
    b>>=1;
  }
  return res;
}

void solve(){
  cin >> n >> k >> s >> t;

  vector<vector<ll>> macierz = {{MOD-1,0,1},{0,MOD-1,1},{MOD-1,(1-n+MOD)%MOD,n}};

  powers_prime[0][0] = 1;
  powers_prime[1][0] = 1;
  for(int i = 1; i < n; i++){
    powers_prime[0][i] = powers_prime[0][i-1]*prime[0];
    powers_prime[1][i] = powers_prime[1][i-1]*prime[1];
  }

  for(int i = 0; i < n; i++){
    hash1[0] = hash1[0] * prime[0] + s[i];
    hash1[1] = hash1[1] * prime[1] + s[i];

    hash2[0][i] = (i-1 < 0 ? 0 : hash2[0][i-1]) * prime[0] + t[i];
    hash2[1][i] = (i-1 < 0 ? 0 : hash2[1][i-1]) * prime[1] + t[i];
  }

  for(int przesuniecie = 0; przesuniecie < n; przesuniecie++){
    if(hash1[0] == przesun(przesuniecie,0) && hash1[1] == przesun(przesuniecie,1)){
      wynikowe_przesuniecia.pb(przesuniecie);
    }
  }

  macierz = binpow(macierz, k);
  int zero = 1;
  int reszta = 0;
  int suma = 1;
  int wynik_zero = ((zero*macierz[0][0])%MOD+(reszta*macierz[0][1])%MOD+(suma*macierz[0][2])%MOD)%MOD;
  int wynik_reszta = ((zero*macierz[1][0])%MOD+(reszta*macierz[1][1])%MOD+(suma*macierz[1][2])%MOD)%MOD;

  for(auto el : wynikowe_przesuniecia){
    if(el == 0){
      wynik = (wynik+wynik_zero)%MOD;
    } else{
      wynik = (wynik+wynik_reszta)%MOD;
    }
  }
  cout << wynik << endl;
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