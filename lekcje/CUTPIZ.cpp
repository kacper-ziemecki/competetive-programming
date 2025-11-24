#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n,res=0;
  cin >> n;
  vector<ll> list(n), angles(n);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    if(i==n-1) angles[i] = 360+list[0]-list[i];
    else angles[i] = list[(i+1)%n]-list[i]; 
  }
  ll g = angles[0];
  for(auto el : angles) g = __gcd(g, el);
  for(auto el : angles) res += el/g - 1;
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}