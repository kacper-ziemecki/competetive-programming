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
  vector<ll> l(n, 0ll);
  for(auto &el : l) cin >> el;
  ll prev = 0;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    if(l[i] > 0 && prev != i){
      res++;
      prev = i+1;
    }
    if(l[i] >= 0 && prev == i) prev++;
  }
  if(prev != n) res++;
  ll suma =0;
  for(auto el : l) suma += abs(el);
  cout << suma << " " << res << endl;
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