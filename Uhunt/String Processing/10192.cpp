#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll score(char a, char b){
  if(a == b) return 1;
  else return -10000; 
}

void solve(string a, string b)
{
  ll n = a.size(), m = b.size();
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++){
      dp[i][j] = max({dp[i-1][j-1]+score(a[i-1], b[j-1]), dp[i-1][j], dp[i][j-1]});
    }
  }
  // for(auto sub : dp){
  //   for(auto el : sub) cout << el << " ";
  //   cout << endl;
  // }
  cout << dp[n][m];
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
  string a,b;
  ll t=0;
  while(getline(cin, a), getline(cin, b), !cin.eof()){
    cout << "Case #" << ++t << ": you can visit at most ";
    solve(a,b);
    cout << " cities.\n";
  }
}