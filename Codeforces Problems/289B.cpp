#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll cost(vector<vector<ll>>& list, ll n, ll m, ll d, ll k){
  ll res = 0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      res += abs(list[i][j]-k)/d;
    }
  }
  return res;
}

ll iterations=0;

void solve()
{
  ll n,m,d,l=0,r=LLONG_MIN, mn=LLONG_MAX;
  cin >> n >> m >> d;
  vector<vector<ll>> list(n, vector<ll>(m, 0));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++) cin >> list[i][j];
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(abs(list[i][j] - list[0][0])%d != 0){
        cout << -1 << endl; return;
      }
      mn = min(mn, list[i][j]); r = max(r, list[i][j]);
    }
  }
  r -= mn;
  r /= d;
  while(l+1 < r){
    // if(iterations++ > 100) break;
    ll mid1 = l+(r-l+2)/3;
    ll mid2 = l+(r-l)*2/3;
    if(mid1 > mid2) swap(mid1, mid2);
    // dbg(l, mid1, mid2, r);
    if(cost(list, n, m, d, mn+mid1*d) < cost(list, n, m, d, mn+mid2*d)){
      r = mid2-1;
    } else{
      l = mid1;
    }
  }
  // dbg(mn+l*d, mn+r*d);
  ll res = LLONG_MAX;
  for(ll i = l-10; i < r+10; i++) res = min(res, cost(list,n,m,d,mn+i*d));
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

  solve();
  
}