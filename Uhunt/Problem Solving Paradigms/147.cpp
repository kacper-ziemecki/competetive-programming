#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll conv[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll dp[30001][11];

ll helper(ll m, ll i){
  if(m==0) return 1;
  if(i==11) return 0;
  if(dp[m][i]!=-1) return dp[m][i];
  if(m-conv[i] < 0) return dp[m][i] = helper(m, i+1);
  return dp[m][i] = helper(m, i+1)+helper(m-conv[i], i);
}

void solve(ld k){
  ll n=k*100;
  if(n%5) n++;
  string res = to_string(helper(n, 0));
  if(k >= 100){
    cout << fixed << setprecision(2) << k;
  }else if(k >= 10){
    cout << " " << fixed << setprecision(2) << k;
  }else{
    cout << "  " << fixed << setprecision(2) << k;
  }
  cout << string(17-res.size(), ' ') << res << endl;
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

  for(ll i = 0; i < 30001; i++){
    for(ll j = 0; j < 11; j++) dp[i][j]=-1;
  }

  ld n;
  while(cin>>n,n!=0) solve(n);
}