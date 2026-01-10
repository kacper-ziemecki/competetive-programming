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

ll n,x;
const ll maxn = 51, maxh = 50*1e3+1;
ll c[maxn], h[maxn];
ll dp[maxh];

// dp[id][happines] => minimum cost

void solve(){
  cin >> n >> x;
  for(int i = 0; i < n; i++){
    cin >> c[i] >> h[i];
  }
  for(int j = 0; j < maxh; j++) dp[j] = LLONG_MAX;

  dp[0] = 0;
  if(c[0] == 0) dp[h[0]] = 0;

  for(int i = 1; i < n; i++){
    for(int j = maxh-1; j >= h[i]; j--){
      if((dp[j-h[i]] != LLONG_MAX) && ((dp[j-h[i]]+c[i]) <= x*i)){
        dp[j] = min(dp[j], dp[j-h[i]]+c[i]);
      }
    }
  }
  for(int i = maxh-1; i >= 0; i--){
    if(dp[i] != LLONG_MAX){
      cout << i << endl;
      return;
    }
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

  int t;
  cin >> t;
  while(t--)
  solve();
}