#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll dp[11]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

bool helper(ll n){
  if(n < 0) return false;
  if(dp[n] != -1) return dp[n];
  if(!helper(n-1) || !helper(n-2)) return dp[n] = true;
  return dp[n] = false;
}

void solve(){
  ll n;
  cin >> n;
  if(helper(n)){
    cout << "ALICE\n";
  } else{
    cout << "BOB\n";
  }
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
  while(t--) solve();
  
  for(int i = 0; i < 11; i++){
    cout << dp[i] << " ";
  }
}