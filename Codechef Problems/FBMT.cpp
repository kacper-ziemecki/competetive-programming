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
  map<string, ll> mp;
  string s;
  for(ll i = 0; i < n; i++){
    cin >> s;
    mp[s]++;
  }
  vector<string> list;
  for(auto el : mp) list.push_back(el.first);
  if(list.empty()) cout << "Draw\n";
  else if(list.size() == 1) cout << list[0] << endl;
  else if(mp[list[0]] == mp[list[1]]) cout << "Draw\n";
  else if(mp[list[0]] > mp[list[1]]) cout << list[0] << endl;
  else cout << list[1] << endl;
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