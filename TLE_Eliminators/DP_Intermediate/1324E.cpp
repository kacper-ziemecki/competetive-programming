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

int n,h,l,r,res=0;
const int maxn = 2e3+1, maxh = 2e3+1;
int lista[maxn];
int dp[maxn][maxh];

bool good(int time){
  return (l <= time && time <= r);
}

void solve(){
  cin >> n >> h >> l >> r;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int id = 0; id < n; id++){
    for(int time = 0; time < h; time++) dp[id][time] = -10000;
  }
  dp[0][lista[0]] = good(lista[0]);
  dp[0][lista[0]-1] = good(lista[0]-1);
  for(int id = 1; id < n; id++){
    for(int time = 0; time < h; time++){
      dp[id][time] = max(dp[id-1][(time-(lista[id])+h)%h]+good(time), dp[id-1][(time-(lista[id]-1)+h)%h]+good(time));
    }
  }
  for(int id = 0; id < n; id++){
    for(int time = 0; time < h; time++){
      res = max(res, dp[id][time]);
    }
  }
  cout << res << endl;
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

  solve();
}