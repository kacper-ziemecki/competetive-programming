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
  ll n;
  cin >> n;
  vector<ll> list(n, 0ll), res1(n, 0ll), res2(n, 0ll);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  for(ll i = 0; i < n; i++){
    res1[i] = (i&1 ? list[n-i/2-1] : list[i/2]);
    res2[i] = (!(i&1) ? list[n-i/2-1] : list[i/2]);
  }
  ll x = res1[0]+res1[1], y = res2[0]+res2[1];
  bool flag1 = true, flag2 = true;
  for(ll i = 1; i < n; i++){
    if(res1[i]+res1[i-1] != x){
      flag1 = false;
    }
  }
  for(ll i = 1; i < n; i++){
    if(res2[i]+res2[i-1] != y){
      flag2 = false;
    }
  } 
  cout << (flag1 || flag2 ? "Yes\n" : "No\n");
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