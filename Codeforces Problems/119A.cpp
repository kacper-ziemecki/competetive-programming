#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll a,b,c;
  cin >> a >> b >> c;
  ll flag = true;
  while(true){
    if(flag){
      flag = false;
      if(c == 0){
        cout << 1 << endl;
        return;
      }
      c -= __gcd(a,c);
    } else{
      flag = true;
      if(c == 0){
        cout << 0 << endl;
        return;
      }
      c -= __gcd(b,c);
    }
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


  solve();
  
}