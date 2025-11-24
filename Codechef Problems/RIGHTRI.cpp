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
  ll n,res=0;
  cin >> n;
  for(ll i = 0; i < n; i++){
    ld ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ld A = abs(ax-bx)*abs(ax-bx)+abs(ay-by)*abs(ay-by);
    ld B = abs(bx-cx)*abs(bx-cx)+abs(by-cy)*abs(by-cy);
    ld C = abs(ax-cx)*abs(ax-cx)+abs(ay-cy)*abs(ay-cy);
    if(A+B == C || A+C==B || B+C==A){
      res++;
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
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif


  solve();
  
  
}