#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
 
void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0ll);
  for(auto &el : list) cin >> el;

  bool case1=true, case2=true;
  ll index1=-1, index2=-1;

  for(ll i = 1; i < n; i++){
    if(list[i] > list[i-1]){
      index1 = i;
      break;
    }
  } 
  for(ll i = 1; i < n; i++){
    if(list[i] < list[i-1]){
      index2 = i;
      break;
    }
  }
  if(index2 == -1){
    cout << 0 << endl;
    return;
  }
  if(index1 == -1){
    cout << 1 << endl;
    return;
  }
  for(ll i = index1+1; i < n; i++){
    if(list[i]>list[i-1]){
      case1=false;
    }
  }
  for(ll i = index2+1; i < n; i++){
    if(list[i]<list[i-1]){
      case2=false;
    }
  }
  if(list[n-1] < list[0]) case1 = false;
  if(list[n-1] > list[0]) case2 = false;

  ll res = LLONG_MAX;
  if(case1){
    res = min(res, n-index1+1);
    res = min(res, index1+1);
  }
  if(case2){
    res = min(res, n-index2);
    res = min(res, index2+2);
  }

  if(!case1 && !case2){
    cout << -1 << endl;
  } else{
    cout << res << endl;
  }
}
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
 
  ll t;
  cin >> t;
  while(t--)
  solve();
}