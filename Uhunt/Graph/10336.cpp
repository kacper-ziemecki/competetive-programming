#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void dfs(ll i, ll j, ll n, ll m, vector<string> &adj, char el){
  adj[i][j] = '0';
  vector<ll> dx{-1,0,1,0};
  vector<ll> dy{0,1,0,-1};
  for(ll k = 0; k < 4; k++){
    if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m && adj[i+dx[k]][j+dy[k]] == el) dfs(i+dx[k], j+dy[k], n, m, adj, el);
  }
}
bool compare(pair<ll, char> &one, pair<ll, char> &two){
  if(one.first > two.first) return true;
  if(one.first < two.first) return false;
  return one.second < two.second;
}

void solve(ll t){
  ll n,m;
  cin >> n >> m;
  vector<string> adj(n);
  for(auto &el : adj) cin >> el;
  map<char, ll> res;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(adj[i][j] != '0'){
        res[adj[i][j]]++;
        dfs(i, j, n, m, adj, adj[i][j]);
      }
    }
  }
  vector<pair<ll, char>> ans;
  for(auto el : res) ans.push_back({el.second, el.first});
  sort(ans.begin(), ans.end(), compare);
  cout << "World #" << t << endl;
  for(auto el : ans) cout << el.second << ": " << el.first << endl;
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
  
  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++) solve(i);
}