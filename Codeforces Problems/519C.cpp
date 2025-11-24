#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,m;
  cin >> n >> m;
  ll cnt=0;
  while(true){
    cnt++;
    if(n > m && n >= 2 && m >= 1){
      n -= 2;
      m--;
      continue;
    } else if(n <= m && n >= 1 && m >= 2){
      n--;
      m -= 2;
      continue;
    }
    break;
  }
  cout << cnt-1 << endl;
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
  
  solve();
  
}