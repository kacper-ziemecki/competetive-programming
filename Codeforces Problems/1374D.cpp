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
  vector<ll> list(n);
  map<ll,ll> mp;
  for(auto &el : list) cin >> el;
  for(auto &el : list){
    el = (el%k==0 ? 0 : k-(el%k));
    mp[el]++;
  }
  ll res = 0;
  for(auto el : mp){
    if(el.first==0) continue;
    res = max(res, (el.second-1)*k+el.first+1);
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