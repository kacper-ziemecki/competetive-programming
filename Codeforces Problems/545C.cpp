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
  vector<pair<ll,ll>> list(n);
  for(auto &el : list) cin >> el.first >> el.second;
  ll prev = LLONG_MIN;
  for(ll i = 0; i < n; i++){
    if(list[i].first-list[i].second > prev){
      res++;
      prev = list[i].first;
    } else if(list[i].first+list[i].second < (i+1==n?LLONG_MAX:list[i+1].first)){
      res++;
      prev = list[i].first+list[i].second;
    } else{
      prev = list[i].first;
    }
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