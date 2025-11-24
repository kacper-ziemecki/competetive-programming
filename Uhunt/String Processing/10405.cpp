#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<string> a,b;
vector<vector<ll>> dp;
vector<vector<pair<ll,ll>>> p;

ll score(string a, string b){
  if(a==b) return 1;
  return LLONG_MIN;
}

ll helper(ll i, ll j){
  if(dp[i][j]!=LLONG_MIN) return dp[i][j];
  if(i==0 || j==0) return dp[i][j]=0;

  if(dp[i][j] < helper(i-1, j-1)+score(a[i-1],b[j-1])){
    dp[i][j] = helper(i-1, j-1)+score(a[i-1],b[j-1]);
    p[i][j] = {i-1, j-1};
  }
  if(dp[i][j] < helper(i-1, j)){
    dp[i][j] = helper(i-1, j);
    p[i][j] = p[i-1][j];
  }
  if(dp[i][j] < helper(i, j-1)){
    dp[i][j] = helper(i, j-1);
    p[i][j] = p[i][j-1];
  }
  return dp[i][j];
}

void solve(){
  a.clear();b.clear();
  string cur;
  while(cin>>cur, cur != "#") a.push_back(cur);
  while(cin>>cur, cur !="#") b.push_back(cur);
  dp.assign(a.size()+1, vector<ll>(b.size()+1, LLONG_MIN));
  p.assign(a.size()+1, vector<pair<ll,ll>>(b.size()+1, {-1,-1}));
  helper(a.size(), b.size());
  pair<ll,ll> res = p[a.size()][b.size()];
  vector<string> ans;
  while(res.first!=0&&res.second!=0){
    ans.push_back(a[res.first]);
    res = p[res.first][res.second];
  }
  ans.push_back(a[res.first]);
  reverse(ans.begin(), ans.end());
  for(auto el : ans) cout << el << " ";
  cout << endl;
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

  while(!cin.eof()) solve();
  
}