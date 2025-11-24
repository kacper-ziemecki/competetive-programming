#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n,x;
  cin >> n >> x;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  bool all = true, any = false;
  for(auto &el : list){
    if(el == x) any = true;
    else all = false;
  }
  if(all){ cout << 0 << endl; return; }
  else if(any){ cout << 1 << endl; return; }

  ll suma = 0;
  for(auto el : list) suma += x-el;
  cout << (suma == 0 ? 1 : 2) << endl;
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