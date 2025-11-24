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
  string s;
  cin >> n >> s;
  unordered_map<char, vector<ll>> mp;
  for(ll i = 0; i < n; i++){
    if(mp.count(s[i])) mp[s[i]].push_back(i);
    else mp[s[i]] = {i};
  }
  ll res = LLONG_MAX;
  for(ll i = 0; i < n; i++){
    ll j = i;
    bool flag = true;
    for(auto &[a, b] : mp){
      ll idx = lower_bound(b.begin(), b.end(), i) - b.begin(); 
      if(idx == b.size()){ flag = false; break; }
      j = max(j,b[idx]);
    }
    if(flag) res = min(res, j-i+1);
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