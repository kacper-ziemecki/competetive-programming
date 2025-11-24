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
  ll n,res=0;
  cin >> n;
  vector<ll> list(n), suma(n);
  vector<bool> vis(n, false);
  vector<pair<ll,ll>> minimums;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    if(list[i] >= 0){
      vis[i] = true; 
      res++; 
    }
    if(list[i] < 0) minimums.push_back({list[i], i});
    suma[i] = (i?suma[i-1]:0)+(vis[i]?list[i]:0);
  }
  sort(minimums.begin(), minimums.end(), greater<>());
  // for(auto el : suma) cout << el << " ";
  // cout << endl;
  for(auto el : minimums){
    bool flag = true;
    for(ll i = el.second; i < n; i++){
      if(suma[i]+el.first < 0) flag = false;
    }
    if(flag){
      res++;
      for(ll i = el.second; i < n; i++) suma[i] += el.first;
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