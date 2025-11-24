#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool check(vector<ll>& list, ll k, ll mid){
  ll last = -1e9;
  for(auto el : list){
    if(el-mid >= last){
      k--;
      last = el;
    }
  }
  return k <= 0;
}

void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  ll l = 0, r = 1e9;
  while(l < r){
    ll mid = (l+r+1)/2;
    if(check(list,k,mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
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