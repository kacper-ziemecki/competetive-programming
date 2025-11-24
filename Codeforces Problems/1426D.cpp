#include <bits/stdc++.h>
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
	ll n;
  cin >> n;
  vector<ll> list(n), pref(n);
  for(auto &el : list) cin >> el;
  pref[0] = list[0];
  for(ll i = 1; i < n; i++) pref[i] = pref[i-1]+list[i];
  map<ll,ll> mp;
  ll res = 0, last = -1;
  for(ll i = 0; i < n; i++){
    if((mp.count(-pref[i]) && mp[-pref[i]] >= last) || (pref[i] == 0 && last == -1)){
      last = i-1;
      res++;
      // dbg(i);
    } 
    mp[-pref[i]] = i;
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

  solve();
}