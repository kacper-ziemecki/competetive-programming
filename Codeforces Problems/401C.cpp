#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m;
  cin >> n >> m;
  if(n-1 > m || n*2+2 < m){
    cout << -1 << endl; return;
  }
  if(n-1 == m){
    for(ll i = 0; i < n-1;i++){
      cout << "01";
    }
    cout << "0\n"; 
    return;
  }
  for(ll i = 0; i < n; i++){
    if(m-2 < n-i-1){
      cout << "10";
      m--;
    } else{
      cout << "110";
      m-=2;
    } 
  }
  if(m>0){
    cout << string(m, '1');
  }
  cout << endl;
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