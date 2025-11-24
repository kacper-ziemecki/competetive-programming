#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll t)
{
  if(t!=1) cout << endl;
  string a,b;
  getline(cin, a);
  getline(cin, b);
  ll n = a.size(), m = b.size();
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  vector<vector<vector<ll>>> p(n+1, vector<vector<ll>>(m+1, {-1,-1,-1}));
  for(ll i = 0; i < m+1; i++) dp[0][i] = i;
  for(ll i = 0; i < n+1; i++) dp[i][0] = i;
  p[0][0] = {0, 0, -1};
  for(ll i = 1; i < m+1; i++) p[0][i] = {0, i-1, 2};
  for(ll i = 1; i < n+1; i++) p[i][0] = {i-1, 0, 1};
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++){
      ll del = dp[i-1][j]+1;
      ll add = dp[i][j-1]+1;
      ll replace = dp[i-1][j-1]+1;
      ll compare = dp[i-1][j-1]+(a[i-1]==b[j-1]?0:100000);
      dp[i][j] = min({del, add, replace, compare});
      if(dp[i][j] == del){
        p[i][j] = {i-1,j, 1};
      } else if(dp[i][j] == add){
        p[i][j] = {i, j-1, 2};
      } else if(dp[i][j] == replace){
        p[i][j] = {i-1,j-1, 3};
      } else if(dp[i][j] == compare){
        p[i][j] = {i-1, j-1, 4};
      }
    }
  }
  vector<ll> cur=p[n][m];
  ll cnt=0;
  while(cur[2] != -1){
    if(cur[2] != 4) cnt++;
    cur = p[cur[0]][cur[1]];
  }
  cout << cnt << endl;
  cur=p[n][m];
  ll i=0;
  while(cur[2] != -1){
    if(cur[2] == 1){
      cout << ++i << " Delete " << cur[0]+1 << endl;
    } else if(cur[2] == 2){
      cout << ++i << " Insert " << cur[0]+1 << "," << b[cur[1]] << endl;
    } else if(cur[2] == 3){
      cout << ++i << " Replace " << cur[0]+1 << "," << b[cur[1]] << endl;
    }
    cur = p[cur[0]][cur[1]];
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
  ll t=0;
  while(!cin.eof()) solve(++t);
}