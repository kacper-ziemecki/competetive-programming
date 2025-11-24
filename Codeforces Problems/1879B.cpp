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
  vector<ll> a(n, 0), b(n, 0);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  ll res1=0,res2=0;
  ll minHorizontal = LLONG_MAX;
  ll minVertical = LLONG_MAX;
  for(auto el : a) minVertical = min(minVertical, el);
  for(auto el : b) minHorizontal = min(minHorizontal, el);
  for(auto el : b) res1 += el + minVertical;
  for(auto el : a) res2 += el + minHorizontal;
    
  cout << min(res1, res2) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}