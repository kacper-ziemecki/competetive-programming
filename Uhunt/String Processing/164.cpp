#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

enum {
  DEL = 1,
  INS = 2,
  CHG = 3,
  CMP = 4
};

void solve(string a, string b)
{
  ll n = a.size(), m = b.size();
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  vector<vector<vector<ll>>> p(n+1, vector<vector<ll>>(m+1, {0,0,0}));
  for(ll i = 1; i < n+1; i++){
    dp[i][0] = i;
    p[i][0] = {i-1, 0, DEL};
  }
  for(ll i = 1; i < m+1; i++){
    dp[0][i] = i;
    p[0][i] = {0, i-1, INS};
  }
  p[0][0] = {0, 0, -1};
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++){
      ll del = dp[i-1][j]+1;
      ll ins = dp[i][j-1]+1;
      ll chg = dp[i-1][j-1]+1;
      ll cmp = dp[i-1][j-1]+(a[i-1]==b[j-1]?0:100000);
      ll mn = min({del,ins,chg,cmp});
      dp[i][j] = mn;
      if(del == mn){
        p[i][j] = {i-1, j, DEL};
      } else if(ins == mn){
        p[i][j] = {i, j-1, INS};
      } else if(chg == mn){
        p[i][j] = {i-1, j-1, CHG};
      } else{
        p[i][j] = {i-1, j-1, CMP};
      }
    }
  }
  vector<ll> cur = p[n][m];
  while(cur[2] != -1){
    if(cur[2] == DEL){
      cout << "D" << a[cur[0]] << (cur[0]+1 >= 10 ? to_string(cur[0]+1) : '0'+to_string(cur[0]+1));
    } else if(cur[2] == INS){
      cout << "I" << b[cur[1]] << (cur[0]+1 >= 10 ? to_string(cur[0]+1) : '0'+to_string(cur[0]+1));
    } else if(cur[2] == CHG){
      cout << "C" << b[cur[1]] << (cur[0]+1 >= 10 ? to_string(cur[0]+1) : '0'+to_string(cur[0]+1));
    }
    // cout << endl;
    // dbg(cur[0], cur[1], cur[2]);
    cur = p[cur[0]][cur[1]];
  }
  cout << "E\n";
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
  string s,a,b;
  while(getline(cin, s)){
    stringstream stream;
    stream << s;
    stream >> a >> b;
    if(a == "#") break;
    solve(a,b);
  }
}