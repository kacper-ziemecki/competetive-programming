#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0ll);
  for(auto &el : list) cin >> el;
  ll m;
  cin >> m;
  vector<pair<ll, ll>> list2(m, {0, 0});
  for(auto &el : list2) cin >> el.first >> el.second;
  for(ll i = 0; i < m; i++){
    if(list2[i].first == 1){
      list[list2[i].first] += list[list2[i].first-1] - list2[i].second;
      list[list2[i].first-1] = 0;
    } else if(list2[i].first == n){
      list[list2[i].first-2] += list2[i].second-1;
      list[list2[i].first-1] = 0;
    } else{
      list[list2[i].first-2] += list2[i].second-1;
      list[list2[i].first] += list[list2[i].first-1] - list2[i].second;
      list[list2[i].first-1] = 0;
    }
  }
  for(auto el : list) cout << el << endl;
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