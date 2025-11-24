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
  ll n,m;
  cin >> n >> m;
  vector<string> l(n, " ");
  for(auto &el : l) cin >> el;
  for(ll i = 0; i < n; i++){
    bool flag = true;
    for(ll j = 0; j < m; j++){
      if(l[i][j] == 'S') flag = false;
    }
    if(flag){
      for(ll j = 0; j < m; j++){
        l[i][j] = '#';
      }
    }
  }
  for(ll i = 0; i < m; i++){
    bool flag = true;
    for(ll j = 0; j < n; j++){
      if(l[j][i] == 'S') flag = false;
    }
    if(flag){
      for(ll j = 0; j < n; j++){
        l[j][i] = '#';
      }
    }
  }
  ll res = 0;
  for(auto sub : l){
    for(auto el : sub){
      if(el == '#') res++;
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
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  
  solve();
  
}