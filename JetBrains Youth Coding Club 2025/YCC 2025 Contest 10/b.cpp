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


void solve(){
  int n,k;
  cin >> n >> k;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  sort(lista.begin(), lista.end());
  for(int i = 0; i < n; i++){
    if(k == 0) break;

    if(lista[i] < 0){
      lista[i] *= -1;
      k--;
    } else{
      break;
    }
  }
  if(k&1){
    int mn = INT_MAX;
    for(auto &el : lista) mn = min(mn, el);
    for(auto &el : lista){
      if(el == mn){
        el *= -1;
        break;
      }
    }
  }
  int suma = 0;
  for(auto el : lista) suma += el;
  cout << suma << endl;
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