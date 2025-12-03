#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,suma;
vector<int> lista,res;
void solve(){
  cin >> n;
  lista.resize(n);
  res.assign(n, -1);
  for(int i = 0; i+1 < n; i++){
    cout << i << ' ' << i+1 << endl;
    cin >> lista[i];
  }
  for(int i = 0; i+1 < n; i++){
    if(lista[i] == 2){
      res[i] = 1;
      res[i+1] = 1;
      for(int j = i+2; j < n; j++){
        res[j] = lista[j-1]-res[j-1];
      }
      for(int j = i-1; j >= 0; j--){
        res[j] = lista[j]-res[j+1];
      }
      cout << n << endl;
      for(auto el : res) cout << el << ' ';
      cout << endl;
      return;
    } else if(lista[i] == 0){
      res[i] = 0;
      res[i+1] = 0;
      for(int j = i+2; j < n; j++){
        res[j] = lista[j-1]-res[j-1];
      }
      for(int j = i-1; j >= 0; j--){
        res[j] = lista[j]-res[j+1];
      }
      cout << n << endl;
      for(auto el : res) cout << el << ' ';
      cout << endl;
      return;
    }
  }
  cout << "0 2" << endl;
  cin >> suma;
  cout << n << endl;
  if(suma){
    for(int i = 0; i < n; i++){
      if(i&1) cout << "0 ";
      else cout << "1 ";
    }
    cout << endl;
  } else{
    for(int i = 0; i < n; i++){
      if(i&1) cout << "1 ";
      else cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
 
// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}