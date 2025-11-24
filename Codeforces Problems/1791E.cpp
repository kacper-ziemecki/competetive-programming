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
  ll n,res=0;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll cnt=0;
  for(auto el : list){
    if(el < 0) cnt++;
  }
  if(cnt&1){
    ll minimum = INT_MAX;
    for(auto el : list){
      minimum = min(minimum, abs(el));
      res += abs(el);
    }
    res -= 2*minimum;
  } else{
    for(auto el : list) res += abs(el);
  }
  cout << res << endl;

}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}