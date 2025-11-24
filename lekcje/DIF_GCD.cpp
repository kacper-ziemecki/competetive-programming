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
  ll n,m;
  cin >> n >> m;
  pair<ll,ll> ans = {m, m};
  for(ll i = m; i >= max(m-n,n); i--){
    for(ll j = 1; j*j <= i; j++){
      if(i % j == 0 && j >= n && ans.second-ans.first < i-j) ans = {j, i};
      if(i % j == 0 && (i/j) >= n && ans.second-ans.first < i-(i/j)) ans = {i/j, i};
    }
    if(ans.second-ans.first > i-n) break;
  }
  cout << ans.first << " " << ans.second << endl;
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