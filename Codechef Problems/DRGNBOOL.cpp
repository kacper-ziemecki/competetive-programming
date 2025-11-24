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
  ll n,m,res=0;
  cin >> n >> m;
  vector<pair<ll,ll>> a(n), b(m);
  map<ll, ll> mp1, mp2;
  for(auto &el : a) cin >> el.first >> el.second;
  for(auto &el : b) cin >> el.first >> el.second;

  for(auto el : a) mp1[el.second]+=el.first;
  for(auto el : b) mp2[el.second]+=el.first;

  for(auto el : mp1){
    cout << el.first << " " << el.second << endl;
  }
  cout << endl;
  for(auto el : mp2){
    cout << el.first << " " << el.second << endl;
  }
  cout << endl;
  cout <<"------------\n";

  for(auto el : mp1){
    // dbg(max(0ll, mp2[el.first]-el.second));
    res += max(0ll, mp2[el.first]-el.second);
  }
  cout << res << endl;
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
  while(t--) solve();
  
  
}