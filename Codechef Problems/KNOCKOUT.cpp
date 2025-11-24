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
  vector<pair<ll, ll>> list(16);
  vector<ll> res(16);
  for(ll i = 0; i < 16; i++){
    cin >> list[i].first; 
    list[i].second = i;
  }
  sort(list.begin(), list.end());
  // for(auto el : list) cout << el.first << " ";
  // cout << endl;
  for(ll i = 0; i < 16; i++){
    ll ans=-1, j=i+1;
    while(j > 0){
      ans++; 
      j /= 2;
    }
    // dbg(list[i].first, list[i].second, i, ans);
    res[list[i].second] = ans;
    // for(auto el : res) cout << el << " ";
    // cout << endl;
  }
  for(auto el : res) cout << el << " ";
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