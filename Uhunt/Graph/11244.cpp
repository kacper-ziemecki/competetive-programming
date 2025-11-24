#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(ll i, ll j, ll n, ll m, vector<string> &adj){
  vector<ll> dx{-1, -1, -1, 0, 1, 1, 1, 0};
  vector<ll> dy{-1, 0, 1, 1, 1, 0, -1, -1};
  for(ll k = 0; k < 8; k++){
    if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m && adj[i+dx[k]][j+dy[k]] == '*') return false;
  }
  return true;
}

void solve(ll n, ll m){
  vector<string> adj(n);
  for(auto &el : adj) cin >> el;
  ll res=0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(adj[i][j] == '*' && check(i, j, n, m, adj)) res++;
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
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
  
  ll n,m;
  while(cin >> n >> m, n != 0 || m != 0) solve(n, m);
}