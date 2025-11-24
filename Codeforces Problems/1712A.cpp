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
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n, 0ll), tmp;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < k; i++){
    tmp.push_back(list[i]);
  }
  sort(tmp.begin(), tmp.end());
  ll res = 0;
  for(ll i = 0; i < k; i++){
    if(tmp[i] > k) res++;
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