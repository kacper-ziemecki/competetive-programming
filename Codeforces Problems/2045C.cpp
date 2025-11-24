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
  string a,b,res(2000001, ' ');
  cin >> a >> b;
  unordered_map<char, ll> mp;
  for(ll i = 0; i < b.size()-1; i++) mp[b[i]] = i;
  // for(auto el : mp) cout << el.first << " " << el.second << endl;
  for(ll i = 1; i < a.size(); i++){
    if(mp.count(a[i]) == 0) continue;
    // dbg(res.size(), a[i], mp[a[i]], i+(b.size()-mp[a[i]]));
    if(res.size() > i+(b.size()-mp[a[i]])){
      // dbg(a.substr(0, i), b.substr(mp[a[i]], b.size()-mp[a[i]]));
      res = a.substr(0, i) + b.substr(mp[a[i]], b.size()-mp[a[i]]);
    }
  }
  if(res.size() == 2000001) cout << -1 << endl;
  else cout << res << endl;
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