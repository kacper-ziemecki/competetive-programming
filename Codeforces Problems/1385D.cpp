#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll helper(ll l, ll r, string& s, char a){
  if(r-l == 1) return (s[l] == a ? 0 : 1);
  ll left = 0, right = 0;
  for(ll i = l; i < l+(r-l)/2; i++){
    if(s[i] != a) left++;
  }
  for(ll i = l+(r-l)/2; i < r; i++){
    if(s[i] != a) right++;
  }
  ll res = min(left+helper(l+(r-l)/2, r, s, char(a+1)), right+helper(l, l+(r-l)/2, s, char(a+1)));
  return res;
}

void solve()
{
  ll n;
  string s;
  cin >> n >> s;
  cout << helper(0, n, s, 'a') << endl;
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