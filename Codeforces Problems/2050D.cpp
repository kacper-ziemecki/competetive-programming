#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  string s,ans;
  cin >> s;
  while(!s.empty()){
    pair<ll,ll> res{s[0]-'0',0};
    for(ll j = 0; j < min(9ll, (ll)s.size()); j++){
      if(s[j]-'0'-j > res.first){
        res = {s[j]-'0'-j, j};
      }
    }
    // dbg(res.first,res.second);
    ans += char(res.first+'0');
    s.erase(res.second, 1);
   }
   // cout << "----\n";
   cout << ans << endl;
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