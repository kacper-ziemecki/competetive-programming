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
  ll ones=0,zeros=0;
  for(auto el : b){
    if(el == 0) zeros++;
    else ones++;
  }
  if(ones==0||zeros==0){
    vector<ll> c = a;
    sort(c.begin(), c.end());
    for(ll i = 0; i < n; i++){
      if(a[i] != c[i]){
        cout << "No\n"; return;
      }
    }
  }
  cout << "Yes\n";
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