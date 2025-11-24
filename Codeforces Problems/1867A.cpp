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
  ll n,a;
  cin >> n;
  vector<vector<ll>> list(n, vector<ll>(3, 0ll));
  for(ll i = 0; i < n; i++){
    cin >> a;
    list[i][0] = a;
    list[i][1] = i;
  }
  sort(list.begin(), list.end());
  for(ll i = 0; i < n; i++){
    list[i][2] = n-i;
  }
  vector<ll> res(n, 0);
  for(ll i = 0; i < n; i++){
    res[list[i][1]] = list[i][2];
  }
  for(auto el : res) cout << el << " ";
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
  while(t--) solve();
  
}