#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool compute(ll mid, ll m, vector<vector<ll>> &list){
  ll res = 0;
  for(auto el : list){
    res += (mid/(el[0]*el[1]+el[2]))*el[1];
    res += (mid - ((mid/(el[0]*el[1]+el[2]))*(el[0]*el[1]+el[2])))/ el[0];
  }
  return res >= m;
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> list(n, vector<ll>(3, 0ll));
  for(auto &sub : list){
    for(auto &el : sub) cin >> el;
  }
  ll l = 0, r = 1e9;
  while(l < r){
    ll mid = (l+r)/2;
    dbg(l, mid, r);
    if(compute(mid, m, list)){
      r = mid;
    } else{
      l = mid+1;
    }
  }
  cout << r << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../in.in", "r", stdin);
  freopen("../../../out.out", "w", stdout);
#endif

  solve();
  
} 