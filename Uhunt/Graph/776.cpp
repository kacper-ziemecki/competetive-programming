#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool inBounds(ll x, ll y, ll n, ll m){
  if(x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}

void dfs(ll x, ll y, ll n, ll m, vector<string>& adj, vector<vector<ll>>& res, char el, ll cnt){
  adj[x][y] = ' ';
  res[x][y] = cnt;
  vector<ll> dx{-1, 0, 1, 1, 1, 0, -1, -1};
  vector<ll> dy{-1, -1, -1, 0, 1, 1, 1, 0};
  for(ll i = 0; i < 8; i++){
    ll x1=x+dx[i],y1=y+dy[i];
    if(inBounds(x1,y1,n,m) && adj[x1][y1] == el) dfs(x1,y1,n,m,adj,res,el,cnt);
  }
}

void solve(){
  vector<string> adj;
  vector<vector<ll>> res;
  vector<vector<string>> ans;
  string s;
  char a;
  ll n=0,m=0;
  while(getline(cin, s) && !(s[0] == '%' && s.size()==2)){
    n++;
    stringstream stream;
    stream << s;
    adj.push_back("");
    while(stream >> a) adj.back() += a;
  }
  if(n) m = adj[0].size();
  res.assign(n, vector<ll>(m, 0));
  ans.assign(n, vector<string>(m, ""));
  ll cnt=1;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(!res[i][j]){
        dfs(i,j,n,m,adj,res,adj[i][j],cnt++);
      }
    }
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      ans[i][j] = to_string(res[i][j]);
    }
  }
  for(ll j = 0; j < m; j++){
    ll cnt=0;
    for(ll i = 0; i < n; i++){
      cnt = max(cnt, (ll)ans[i][j].size());
    }
    for(ll i = 0; i < n; i++){
      while(ans[i][j].size() < cnt) ans[i][j] = ' ' + ans[i][j];
    }
  }
  if(n == 0 || m == 0){ cout << "%\n"; return; }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(j != 0) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
  cout << "%\n";
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

  while(!cin.eof()){
    solve();
  }
}