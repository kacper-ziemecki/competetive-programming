#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

pair<ll,ll> move(ll x,ll y,ll n,ll m,vector<string>& adj){
  if(adj.at(x).at(y) == 'N'){
    if(x-1 >= 0 && x-1 < n && y >= 0 && y < m) return {x-1, y};
    return {-1,-1};
  } else if(adj[x][y] == 'S'){
    if(x+1 >= 0 && x+1 < n && y >= 0 && y < m) return {x+1, y};
    return {-1,-1};
  } else if(adj[x][y] == 'E'){
    if(x >= 0 && x < n && y+1 >= 0 && y+1 < m) return {x,y+1};
    return {-1,-1};
  } else if(adj[x][y] == 'W'){
    if(x >= 0 && x < n && y-1 >= 0 && y-1 < m) return {x,y-1};
    return {-1,-1};
  } else{
    return {-1,-1};
  }
}

pair<ll,ll> dfs1(ll x,ll y,ll n,ll m,vector<string>& adj,vector<vector<bool>>& vis){
  vis[x][y] = true;
  pair<ll,ll> xy = move(x,y,n,m,adj);
  if((xy.first != -1 && vis[xy.first][xy.second]) || xy.first == -1){
    return xy;
  } else{
    return dfs1(xy.first,xy.second,n,m,adj,vis);
  }
}

ll dfs2(ll x1,ll y1,ll x2,ll y2,ll n,ll m, vector<string>&adj){
  if(x1 == x2 && y1 == y2){
    return 0;
  }
  pair<ll,ll> xy = move(x1,y1,n,m,adj);
  return 1 + dfs2(xy.first,xy.second,x2,y2,n,m,adj);
}

void solve(ll n, ll m, ll x){
  vector<string> adj(n);
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for(auto &el : adj) cin >> el;
  pair<ll, ll> xy = dfs1(0,x-1,n,m,adj, vis);
  ll one=0,two=0;
  if(xy.first == -1){
    one = dfs2(0,x-1,xy.first,xy.second,n,m,adj);
    cout << one << " step(s) to exit\n";
  } else{
    pair<ll,ll> nM = move(xy.first,xy.second,n,m,adj);
    one = dfs2(0,x-1,xy.first,xy.second,n,m,adj);
    two = dfs2(nM.first,nM.second,xy.first,xy.second,n,m,adj);
    cout << one << " step(s) before a loop of " << two+1 << " step(s)\n";
  }
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

  ll n,m,x;
  while(cin >> n >> m >> x, n != 0 || m != 0 || x != 0) solve(n,m,x);
}