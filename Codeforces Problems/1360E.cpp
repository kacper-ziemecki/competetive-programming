#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool cant(vector<string>& dp, ll i, ll j, ll n){
  char one = (i+1 >= n ? '1' : dp[i+1][j]);
  char two = (j+1 >= n ? '1' : dp[i][j+1]);
  if(one == '1' || two == '1') return false;
  return true;
}

void solve(){
  ll n;
  cin >> n;
  vector<string> list(n), dp(n, string(n, '0'));
  for(auto &el : list) cin >> el;
  for(ll i = n-1; i >= 0; i--){
    for(ll j = n-1; j >= 0; j--){
      if(list[i][j]=='1' && cant(dp, i, j, n)){
        cout << "NO\n"; return;
      }
      else if(list[i][j] == '1') dp[i][j] = '1';
    }
  }
  cout << "YES\n";
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