#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  int n,x,a,b;
  cin >> n;
  pair<int,int> naroznik = {-1,-1};
  int jeden,dwa;
  vector<pair<int,int>> lista;
  for(int i = 1; i <= n*n; i++){
    cout << "? 1 " << i << endl;
    cin >> x;
    lista.pb({x,i});
  }
  sort(lista.begin(), lista.end(), greater<>());
  naroznik = lista[0];
  int odleglosc = lista[1].first;
  for(int i = 1; i < lista.size(); i++){
    if(lista[i].first != odleglosc) break;
    cout << "? " << naroznik.second << ' ' << lista[i].second << endl;
    cin >> x;
    if(x == n-1){
      jeden = naroznik.second;
      dwa = lista[i].second;
    }
  }
  vector<vector<int>> wynik(n, vector<int>(n, -1));
  wynik[0][0] = dwa;
  wynik[0][n-1] = jeden;
  for(int i = 1; i <= n*n; i++){
    cout << "? " << dwa << ' ' << i << endl;
    cin >> a;
    cout << "? " << jeden << ' ' << i << endl;
    cin >> b;
    wynik[(a+b-(n-1))/2][a - (a+b-(n-1))/2] = i;
  }
  cout << "!" << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << wynik[i][j] << ' ';
    }
    cout << endl;
  }
}

int main()
{


  int t;
  cin >> t;
  while(t--)
  solve();
}