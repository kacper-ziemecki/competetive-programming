#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll w,h,n;

bool good(ll x){
  return (x/w) * (x / h) >= n;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif

  cin >> w >> h >> n;
  ll l = 0, r = 1;
  while(!good(r)) r <<= 1;
  
  while(r > l+1){
    ll m = (r+l)/2;
    if(good(m)){
      r = m;
    }
    else{
      l = m;
    }
  }
  cout << r << endl;
}