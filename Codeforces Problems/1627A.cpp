#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m,r,c;
  cin >> n >> m >> r >> c;
  vector<string> l(n, " ");
  for(auto &el : l) cin >> el;
  if(l[r-1][c-1] == 'B'){
    cout << 0 << endl;
    return;
  }
  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(l[i][j] == 'B'){
        cnt++;
        if(i == r-1 || j == c-1){
          cout << 1 << endl;
          return;
        }
      }
    }
  }
  if(!cnt){
    cout << -1 << endl;
  } else{
    cout << 2 << endl;
  }
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
} 