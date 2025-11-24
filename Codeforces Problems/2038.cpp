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
  vector<ll> list(n), res;
  for(auto &el : list) cin >> el;
  unordered_map<ll, ll> mp;
  for(auto el : list) mp[el]++;
  for(auto &el : mp){
    while(el.second >= 2){
      el.second -= 2;
      res.push_back(el.first);
    }
  }
  sort(res.begin(), res.end());
  if(res.size() < 4){
    cout << "NO\n"; return;
  }
  cout << "YES\n";
  ll x,y;
  if(abs(res[0]-res[res.size()-1])*abs(res[1]-res[res.size()-2]) > abs(res[0]-res[res.size()-2])*abs(res[1]-res[res.size()-1])){
    x = res[res.size()-1]; y = res[res.size()-2];
  } else{
    x = res[res.size()-2]; y = res[res.size()-1];
  }
  cout << res[0] << " " << y << " ";
  cout << res[0] << " " << res[1] << " ";
  cout << x << " " << res[1] << " ";
  cout << x << " " << y << endl;

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