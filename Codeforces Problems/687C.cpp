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

const int maxLiczba = 501;
int n,k;
bool dp[maxLiczba][maxLiczba][maxLiczba];
int lista[maxLiczba];

void solve(){
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> lista[i];
  // dp[id][suma1][suma2] = dp[id-1][suma1][suma2] || dp[id-1][suma1-lista[id-1]][suma2] || dp[id-1][suma1-lista[id-1]][suma2-lista[id-1]];
  dp[0][0][0] = true;
  for(int id = 1; id <= n; id++){ // id-ile bierzemy elementow
    for(int suma1 = 0; suma1 <= k; suma1++){
      for(int suma2 = 0; suma2 <= suma1; suma2++){
        dp[id][suma1][suma2] = dp[id-1][suma1][suma2];
        if(suma1-lista[id-1] >= 0) dp[id][suma1][suma2] |= dp[id-1][suma1-lista[id-1]][suma2];
        if(suma2-lista[id-1] >= 0) dp[id][suma1][suma2] |= dp[id-1][suma1-lista[id-1]][suma2-lista[id-1]];
      }
    }
  }
  vector<int> res;
  for(int i = 0; i <= k; i++){
    if(dp[n][k][i]) res.pb(i);
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el << ' ';
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}