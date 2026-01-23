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

// https://szkopul.edu.pl/c/mistrz-programowania-2026/p/r3b/

void solve(){
  int n,k;
  int aktualnaSuma = 0, maksymalnaSuma = 0;
  cin >> n >> k;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  // pierwsze okienko
  for(int i = 0; i < k; i++) aktualnaSuma += lista[i];
  maksymalnaSuma = aktualnaSuma;
  for(int i = k; i < n; i++){
    aktualnaSuma += lista[i];
    aktualnaSuma -= lista[i-k];
    maksymalnaSuma = max(maksymalnaSuma, aktualnaSuma);
  }
  cout << maksymalnaSuma << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../in.in", "r", stdin);
  freopen("../../../out.out", "w", stdout);
#endif

  solve();
}