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
	ll n,m;
  string s,t;
  cin >> n >> m >> s >> t;
  map<char, vector<ll>> mp;
  vector<ll> mn(m), mx(m);
  for(ll i = 0; i < n; i++){
    if(!mp.count(s[i])) mp[s[i]] = {i};
    else mp[s[i]].push_back(i);
  }

  mn[0] = mp[t[0]].front();
  mx[m-1] = mp[t[m-1]].back();

  for(ll i = 1; i < m; i++){
    ll prev = mn[i-1];
    ll l = 0, r = mp[t[i]].size()-1;
    while(l<r){
      ll mid = (l+r)/2;
      if(mp[t[i]][mid] > prev) r = mid;
      else l = mid+1;
    }
    mn[i] = mp[t[i]][r];
  }
  for(ll i = m-2; i >= 0; i--){
    ll prev = mx[i+1];
    ll l = 0, r = mp[t[i]].size()-1;
    while(l<r){
      ll mid = (l+r+1)/2;
      if(mp[t[i]][mid] < prev) l = mid;
      else r = mid-1;
    }
    mx[i] = mp[t[i]][l];
  }
  ll res = LLONG_MIN;
  for(ll i = 1; i < m; i++){
    res = max(res, mx[i]-mn[i-1]);
  }
  cout << res << endl;
  // for(auto el : mn) cout << el << " ";
  // cout << endl;
  // for(auto el : mx) cout << el << " ";
  // cout << endl;

  // warunek : 1≤p1<p2<…<pm≤n trzeba dodac
 
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