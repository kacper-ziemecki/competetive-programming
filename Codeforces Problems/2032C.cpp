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
  ll n,res1=0,res2=0;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  for(ll i = 1; i < n-1; i++){
    if(list[i]+list[i-1] > list.back()) break;
    res1++;
  }
  for(ll i = n-1; i >= 2; i--){
    if(list[i] < list[0]+list[1]) break;
    res2++;
  }
  cout << min(res1,res2) << endl;
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