#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll x,y;
  cin >> x >> y;
  ll power = 1;
  ll last = x;
  ll res = 0;
  for(ll i = 0;;i++){
    if(i&1){
      if(x-power <= y && y <= last){
        res += abs(last - y);
        cout << res << endl;
        return;
      }
      res += abs(last - (x-power));
      last = x-power;
    } else{
      if(last <= y && y <= x+power){
        res += abs(last - y);
        cout << res << endl;
        return;
      }
      res += abs((x+power) - last);
      last = x+power;
    }
    power <<= 1;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  
#endif

  solve();
}