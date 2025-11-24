#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve(ll &t)
{
  string one,two,cur;
  getline(cin, one);
  if(cin.eof()) return;
  getline(cin, two);
  vector<string> a,b;
  if(++t < 10) cout << " ";
  cout << t << ". ";
  for(auto el : one){
    if((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z') || (el >= '0' && el <= '9')) cur+=el;
    else{
      if(!cur.empty()) a.push_back(cur);
      cur.clear();
    }
  }
  if(!cur.empty()) a.push_back(cur);
  cur.clear();
  for(auto el : two){
    if((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z') || (el >= '0' && el <= '9')) cur+=el;
    else{
      if(!cur.empty()) b.push_back(cur);
      cur.clear();
    }
  }
  if(!cur.empty()) b.push_back(cur);
  if(a.empty() || b.empty()){
    cout << "Blank!\n"; return;
  }
  // cout << "a:\n";
  // for(auto el : a) cout << el << " ";
  // cout << endl;
  // cout << "b:\n";
  // for(auto el : b) cout << el << " ";
  // cout << endl;
  if(!cur.empty()) b.push_back(cur);
  ll n = a.size(), m = b.size();
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++){
      dp[i][j] = max({dp[i-1][j-1] + (a[i-1]==b[j-1] ? 1 : -10000), dp[i-1][j], dp[i][j-1]});
    }
  }
  // for(auto sub : dp){
  //   for(auto el : sub) cout << el << " ";
  //   cout << endl;
  // }
  cout << "Length of longest match: "<< dp[n][m] << endl;
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
  while(!cin.eof()){
    solve(t);
  }
}