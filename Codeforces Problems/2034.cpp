#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool dfs(ll i,ll j,ll n,ll m,vector<string>& list,vector<vector<bool>>& vis,map<pair<ll,ll>,bool>& visTmp,vector<vector<bool>>& cycle){
  if(i < 0 || i >= n || j < 0 || j >= m) return false;
  if(list[i][j] == '?' || visTmp[{i,j}]) return true;
  if(vis[i][j]) return cycle[i][j];
  vis[i][j] = true;
  visTmp[{i,j}] = true;

  ll i1=i,j1=j;
  if(list[i][j] == 'R') j1++;
  else if(list[i][j] == 'L') j1--;
  else if(list[i][j] == 'U') i1--;
  else i1++;

  if(!dfs(i1,j1,n,m,list,vis,visTmp,cycle)){
    cycle[i][j]=false;
    return false;
  }
  return true;
}

bool check(ll i,ll j,ll n,ll m,vector<vector<bool>>& cycle){
  if(i-1 >= 0 && cycle[i-1][j]) return true;
  if(i+1 < n && cycle[i+1][j]) return true;
  if(j-1 >= 0 && cycle[i][j-1]) return true;
  if(j+1 < m && cycle[i][j+1]) return true;
  return false;
}
void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> list(n);
  for(auto &el : list) cin >> el;
  vector<vector<bool>> vis(n, vector<bool>(m, false)),cycle(n, vector<bool>(m, true));
  map<pair<ll,ll>,bool> visTmp;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(!vis[i][j] && list[i][j] != '?'){
        visTmp.clear();
        dfs(i,j,n,m,list,vis,visTmp,cycle);
      }
    }
  }
  ll res=0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(list[i][j] == '?'){
        res += check(i,j,n,m,cycle);
      } else if(cycle[i][j]) res++;
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

  ll t;
  cin >> t;
  while(t--)
  solve();
}