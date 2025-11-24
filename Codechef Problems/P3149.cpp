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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  bool plus=false;
  for(auto &el : list) if(el > 0) plus=true;
  if(!plus){
    cout << 0 << endl;
  } else{
    ll a=0,b=n;
    for(ll i = 0; i < n; i++) if(list[i] > 0){a=i; break;}
    for(ll i = n-1; i >= 0; i--) if(list[i] > 0){b=i; break;}
    ll res = 0;
    for(ll i = a; i <= b; i++) if(list[i] < 0) res++;
    cout << res << endl;
  }
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