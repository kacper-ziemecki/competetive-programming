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
  vector<bool> vis(n, false);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  cout << list[0] << " ";
  vis[0] = true;
  for(ll i = 1; i < n; i++){
    if(list[i] != list[i-1]){
      vis[i] = true;
      cout << list[i] << " ";
    }
  }
  for(ll i = 0; i < n; i++){
    if(!vis[i]) cout << list[i] << " ";
  }
  cout << endl;
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