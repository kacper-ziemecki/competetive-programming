#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m,x,y,res=0;
  cin >> n >> m >> x >> y;
  vector<string> list(n, " ");
  for(auto &el : list) cin >> el;
  if(2*x <= y){
    for(ll i = 0; i < n; i++){
      for(ll j = 0 ; j < m; j++){
        if(list[i][j] == '.') res += x;
      }
    }
  } else{
    for(ll i = 0; i < n; i++){
      for(ll j = 1; j < m; j++){
        if(list[i][j] == '.' && list[i][j-1] == '.'){
          res += y;
          list[i][j] = '*';
          list[i][j-1] = '*';
        }
      }
    }
    for(ll i = 0; i < n; i++){
      for(ll j = 0 ; j < m; j++){
        if(list[i][j] == '.') res += x;
      }
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
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}