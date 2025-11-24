#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,res=0;
  cin >> n;
  vector<ll> list1(n), list2(n);
  for(auto &el : list1) cin >> el;
  list2[0] = list1[0];
  for(ll i = 1; i < n; i++) list2[i] = max(list2[i-1], list1[i]);
  for(auto el : list2) cout << el << " ";
  cout << endl;
  for(ll i = 1; i < n; i++){
    if(list2[i-1] > list1[i]) res = max(res, list1[i]+list2[i-1]);
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}