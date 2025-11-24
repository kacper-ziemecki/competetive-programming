#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,x,y;

bool good(ll m){
  m -= min(x,y);
  ll one = m/x, two = m/y;
  return n-1-one-two <= 0 && m >= 0;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif

  cin >> n >> x >> y;

  ll l = min(x, y)-1, r = 1e12;
  while(l+1 < r){
    ll m = (l+r)/2;
    if(good(m)){
      r = m;
    } else{
      l = m;
    }
  }
  cout << r << endl;
}