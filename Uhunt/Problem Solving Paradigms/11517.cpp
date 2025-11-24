#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> conv;
pair<ll,ll> ans;
void helper(ll cur, ll cnt, ll i, ll k, ll n){
  if(cur >= k && cur < ans.first){
    ans = {cur, cnt};
  } else if(cur >= k && cur == ans.first && cnt < ans.second){
    ans = {cur, cnt};
  }
  for(ll j = i; j < n; j++) helper(cur+conv[j], cnt+1, j+1, k, n);

}

void solve(){
  ll k,n;
  cin >> k >> n;
  conv.resize(n);
  for(auto &el : conv) cin >> el;
  ans = {LLONG_MAX, LLONG_MAX};
  helper(0, 0, 0, k, n);
  cout << ans.first << " " << ans.second << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();  
}