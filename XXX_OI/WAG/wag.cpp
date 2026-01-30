#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ull n,d,a,b;
unordered_map<ull,ull> dp;
ull helper(ull n){
  if(dp.count(n)){
    return dp[n];
  }
  dp[n] = ULLONG_MAX;
  for(ull n1 = (n+1)/2 ; (2*n1-n <= d) && (n1 < n) ; n1++){
    dp[n] = min(dp[n], helper(n1)+helper(n-n1)+min((n1*a+(n-n1)*b)%1001,((n-n1)*a+n1*b)%1001));
  }
  return dp[n];
}


void solve(){
  cin >> n >> d >> a >> b;
  dp[1] = 0;
  cout << helper(n) << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  
  solve();
}