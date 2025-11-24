#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void dfs(ll i, ll j, ll n, vector<string> &adj){
  adj[i][j] = '0';
  vector<ll> dirx = {-1, -1, -1, 0, 1, 1, 1, 0};
  vector<ll> diry = {-1, 0, 1, 1, 1, 0, -1, -1};
  for(ll k = 0; k < 8; k++){
    if(i+dirx[k] >= 0 && i+dirx[k] < n && j+diry[k] >= 0 && j+diry[k] < n && adj[i+dirx[k]][j+diry[k]] == '1') dfs(i+dirx[k], j+diry[k], n, adj);
  }
}

void solve(ll n, ll t){
  vector<string> adj(n);
  ll res=0;
  for(auto &el : adj) cin >> el;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(adj[i][j] == '1'){
        res++;
        dfs(i, j, n, adj);
      }
    }
  }
  cout << "Image number " << t << " contains "<< res << " war eagles." << endl;
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
  
  ll n,t=0;
  while(cin >> n) solve(n, ++t);
}