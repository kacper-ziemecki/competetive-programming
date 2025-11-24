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
  ll n,res1=1,res2=1,zeros=0,tmp;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  for(auto el : list){
    if(el == 0) zeros++;
  }
  if(zeros > 1){
    res2 = 0;
  } else if(zeros == 1){
    for(auto el : list) res2 *= (el == 0 ? 1 : el);
  } else{
    for(auto el : list) res1 *= el;
    for(auto el : list){
      tmp = (res1/el) * (el+1);
      res2 = max(res2, tmp);
    }
  }
  cout << res2 << endl;
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
  while(t--) solve();
  
}