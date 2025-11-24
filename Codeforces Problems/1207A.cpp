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
  ll b,p,f,h,c;
  cin >> b >> p >> f >> h >> c;
  ll res=0;
  if(h > c){
    res = min(b/2, p)*h;
    b -= (2*res)/h;
    p -= res/h;
    res += min(b/2, f)*c;
  } else{
    res = min(b/2, f)*c;
    b -= (2*res)/c;
    f -= res/c;
    res += min(b/2, p)*h;
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

  ll t;
  cin >> t;
  while(t--)
  solve();  
  
} 