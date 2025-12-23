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

int bity(int liczba){
  int cnt = 0;
  for(int i = 0;; i++){
    if((liczba>>i) & 1) cnt++;
    else break;
  }
  return cnt;
}

void solve(){
  cin >> n;
  vector<vector<int>> lista(n+1);
  for(int i = 0; i < (1<<n); i++){
    lista[bity(i)].pb(i);
  }
  for(int i = n; i >= 0; i--){
    // dbg(i);
    for(auto el : lista[i]){
      cout << el << ' ';
    }
    // cout << endl;
  }
  cout << endl;
  // cout << "------------------\n";
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

  int t;
  cin >> t;
  while(t--)
  solve();
}