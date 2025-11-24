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
  ll n,d,res=0;
  cin >> n >> d;
  vector<pair<ll,ll>> list(n);
  for(auto &el : list) cin >> el.first >> el.second;
  sort(list.begin(), list.end());
  ll l = 0, cur = 0;
  for(ll r = 0; r < n; r++){
    cur += list[r].second;
    while(list[r].first-list[l].first >= d){
      cur -= list[l].second;
      l++;
    }
    res = max(res, cur);
  }
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