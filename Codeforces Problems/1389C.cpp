#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  string s;
  cin >> s;
  ll n = s.size(), res = 0;
  for(ll i = 0; i < 10; i++){
    ll cur = 0;
    for(ll k = 0; k < n; k++){
      if(s[k] == char(i+'0')) cur++;
    }
    res = max(res, cur);
    for(ll j = 0; j < 10; j++){
      bool flag = true;
      cur = 0;
      for(ll k = 0; k < n; k++){
        if(flag && s[k] == char(i+'0')){
          flag = false;
          cur++;
        }
        else if(!flag && s[k] == char(j+'0')){
          flag = true;
          cur++;
        }
      }
      res = max(res, cur/2*2);
    }
  }
  cout << n - res << endl;
  // cout << " ------------------- \n";
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