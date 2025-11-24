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
  vector<string> a,b;
  string tmp;
  while(getline(cin,tmp)){
    stringstream stream;
    stream << tmp;
    vector<string> cur;
    while(!stream.eof()){
      stream >> tmp;
      cur.push_back(tmp);
    }
    if(cur.size() == 1 && cur[0] == "#") break;
    if(cur.empty()) return;
    for(auto el : cur) a.push_back(el);
  }
  while(getline(cin,tmp)){
    stringstream stream;
    stream << tmp;
    vector<string> cur;
    while(!stream.eof()){
      stream >> tmp;
      cur.push_back(tmp);
    }
    if(cur.size() == 1 && cur[0] == "#") break;
    for(auto el : cur) b.push_back(el);
  }
  if(a.empty()) return;
  ll n = a.size(), m = b.size();
  // cout << "a:\n";
  // for(auto el : a) cout << el << " ";
  // cout << endl;
  // cout << "b:\n";
  // for(auto el : b) cout << el << " ";
  // cout << endl;
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  vector<vector<pair<ll,ll>>> p(n+1, vector<pair<ll,ll>>(m+1, {0, 0}));
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++)           
    {
      ll mx = max({dp[i-1][j-1] + (a[i-1]==b[j-1] ? 1 : -10000), dp[i-1][j], dp[i][j-1]});
      dp[i][j] = mx;
      if(dp[i-1][j-1] + (a[i-1]==b[j-1] ? 1 : -10000) == mx){
        p[i][j] = {i-1, j-1};
      } else if(dp[i-1][j] == mx){
        p[i][j] = {i-1, j};
      } else{
        p[i][j] = {i, j-1};
      }
    }
  }
  vector<string> res;
  pair<ll,ll> cur = {n, m};
  // dbg(a.size(), b.size());
  while(cur.first != 0 && cur.second != 0){
    // dbg(cur.first, cur.second);
    if(a[cur.first-1] == b[cur.second-1]) res.push_back(a[cur.first-1]);
    cur = {p[cur.first][cur.second].first, p[cur.first][cur.second].second};
  }
  reverse(res.begin(), res.end());
  for(auto el : res) cout << el << " ";
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