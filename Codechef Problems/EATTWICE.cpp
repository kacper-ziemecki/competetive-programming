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
  ll n,m;
  cin >> n >> m;
  vector<pair<ll, ll>> list(n);
  for(auto &el : list) cin >> el.first >> el.second;
  map<ll, ll> mp1;
  for(auto el : list){
    if(mp1.count(el.first)) mp1[el.first] = max(mp1[el.first], el.second);
    else mp1[el.first] = el.second;
  }
  vector<ll> list1;
  for(auto el : mp1) list1.push_back(el.second);
  sort(list1.begin(), list1.end(), greater<>());
  cout << list1[0]+list1[1] << endl;
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