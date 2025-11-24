#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(vector<pair<ld,ld>>& list, ld t){
  ld l = LDBL_MIN, r = LDBL_MAX, eps = 1e-13;
  for(auto el : list){
    l = max(l, el.first - el.second*t);
    r = min(r, el.first + el.second*t);
  }
  return l+eps<=r;
}

void solve()
{
  ld n;
  cin >> n;
  vector<pair<ld,ld>> list(n);
  for(auto &el : list) cin >> el.first >> el.second;
  ld l = 0, r = 1e12, eps=1e-13;
  while(l+eps<r){
    ld mid = (l+r)/2.0;
    if(check(list, mid)) r = mid;
    else l = mid;
  }
  cout << fixed << setprecision(7) << r << endl;
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