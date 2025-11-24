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
  vector<pair<string, ll>> list(n);
  map<string, ll> score, cur;
  map<string, ll> idx;
  for(auto &el : list) cin >> el.first >> el.second;
  for(auto el : list) score[el.first] += el.second;
  for(ll i = 0; i < n; i++){
    cur[list[i].first] += list[i].second;
    if(cur[list[i].first] >= score[list[i].first] && idx.count(list[i].first) == 0){
      idx[list[i].first] = i;
    }
  }
  ll mx=LLONG_MIN,index=LLONG_MAX;
  for(auto el : score) mx = max(mx, el.second);
  for(auto el : score){
    if(el.second == mx) index = min(index, idx[el.first]);
  }
  cout << list[index].first << endl;
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