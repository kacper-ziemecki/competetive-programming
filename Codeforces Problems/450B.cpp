#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll a,b,n;
  cin >> a >> b >> n;
  unordered_map<ll,ll> mp;
  vector<ll> list{a,b};
  mp[a]=mp[b]=true;
  for(ll i = 2;; i++){
    ll tmp = list[list.size()-1]-list[list.size()-2];
    if(mp.count(tmp) && mp[tmp] == 2) break;
    mp[tmp]++;
    list.push_back(tmp);
  }
  // dbg(list.size(), n, (n-1)/list.size());
  // for(auto el : list) cout << el << " ";
  // cout << endl;
  ll res = list[(n-1)%list.size()];
  while(res < 0) res += 1000000007;
  cout << res%1000000007 << endl;
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