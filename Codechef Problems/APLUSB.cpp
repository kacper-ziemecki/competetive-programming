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
  vector<ll> a(n), b(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());
  for(ll i = 1; i < n; i++){
    if(a[i]+b[i] != a[0]+b[0]){
      cout << -1 << endl;
      return;
    }
  }
  for(auto el : a) cout << el << " ";
  cout << endl;
  for(auto el : b) cout << el << " ";
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