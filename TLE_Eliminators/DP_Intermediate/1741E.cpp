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

int n;
const int maxn = 2e5+1;
int lista[maxn];
bool dp[maxn];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> lista[i];
    dp[i+1] = false;
  }
  dp[0] = true;
  for(int i = 0; i < n; i++){
    if(dp[i] && i+lista[i]+1 <= n) dp[i+lista[i]+1] = true;
    if(i-lista[i] >= 0 && dp[i-lista[i]]) dp[i+1] = true;
  }
  if(dp[n]){
    cout << "YES\n";
  } else{
    cout << "NO\n";
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