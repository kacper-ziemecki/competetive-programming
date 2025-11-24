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
  vector<pair<ll, ll>> list(3, {0, 0});
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  list[0] = {a, d};
  list[1] = {b, e};
  list[2] = {c, f};
  sort(list.begin(), list.end());
  for(ll i = 1; i < 3; i++){
    if(list[i].first == list[i-1].first && list[i].second != list[i-1].second){
      cout << "NOT FAIR\n"; return;
    } if(list[i].first != list[i-1].first && list[i].second <= list[i-1].second){
      cout << "NOT FAIR\n"; return; 
    }
  }
  cout << "FAIR\n";
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