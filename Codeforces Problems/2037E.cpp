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
  int n;
  cin >> n;
  vector<int> lista(n-1);
  string res;
  for(int i = 2; i <= n; i++){
    cout << "? 1 " << i << endl;
    cin >> lista[i-2]; 
  }  
  bool is_res=false;
  for(auto el : lista){
    if(el > 0) is_res = true;
  }
  if(!is_res){
    cout << "! IMPOSSIBLE" << endl;
    return;
  }
  int poczotek;
  for(int i = 0; i < n-1; i++){
    if(lista[i] > 0){
      poczotek = i;
      break;
    }
  }

  int zera = lista[poczotek];
  int jedynki = poczotek+2-zera;
  // dbg(zera, jedynki);
  for(int i = 0; i < jedynki-1; i++) res += '1';
  for(int i = 0; i < zera; i++) res += '0';
  res += '1';
  // dbg(res);
  for(int i = poczotek+1; i < n-1; i++){
    // dbg(i,res,lista[i],lista[i-1]);
    if(lista[i] > lista[i-1]) res += '1';
    else res += '0';
  }
  cout << "! " << res << endl;
}

int main()
{

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  int t;
  cin >> t;
  while(t--)
  solve();
}