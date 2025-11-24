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
  ll n;
  cin >> n;
  vector<string> list(n), res;
  map<string, bool> mp;
  for(auto &el : list) cin >> el;
  for(ll i = n-1; i >= 0; i--){
    if(mp[list[i]]) continue;
    res.push_back(list[i]);
    mp[list[i]] = true;
  }
  for(auto el : res) cout << el[el.size()-2] << el[el.size()-1];
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

  solve();
  
  
}