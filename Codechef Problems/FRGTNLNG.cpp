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
  ll n,k;
  cin >> n >> k;
  map<string, ll> mp;
  vector<bool> res(n, false);
  string s;
  for(ll i = 0; i < n; i++){
    cin >> s;
    mp[s] = i+1;
  }
  // for(auto el : mp) cout << el.first << " -> " << el.second << endl;
  for(ll i = 0; i < k; i++){
    ll m;
    cin >> m;
    for(ll j = 0; j < m; j++){
      cin >> s;
      if(mp[s]) res[mp[s]-1] = true;
    }
  }
  for(auto el : res) cout << (el ? "YES" : "NO") << " ";
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


  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}