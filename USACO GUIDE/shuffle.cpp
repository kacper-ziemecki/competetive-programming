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
  vector<ll> shuffle(n, 0ll);
  for(auto &el : shuffle) cin >> el;
  vector<string> ids(n, " "),res(n, "");
  for(auto &el : ids) cin >> el;
  for(ll i = 0; i < n; i++){
    res[i] = ids[shuffle[i]-1];
  }
  ids = res;
  for(ll i = 0; i < n; i++){
    res[i] = ids[shuffle[i]-1];
  }
  ids = res;
  for(ll i = 0; i < n; i++){
    res[i] = ids[shuffle[i]-1];
  }
  for(auto el : res) cout << el << endl;

}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);
  
#endif

  solve();
}