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
  string s;
  cin >> s;
  ll a=LLONG_MAX,b=-1,c=LLONG_MAX,d=-1,e=LLONG_MAX,f=-1;
  for(ll i = 0; i < s.size(); i++){
    if(s[i] == 'C'){
      a = min(a, i);
      b = max(b, i);
    }
    if(s[i] == 'E'){
      c = min(c, i);
      d = max(d, i);
    }
    if(s[i] == 'S'){
      e = min(e, i);
      f = max(f, i);
    }
  }
  if(b < c && d < e && b < e) cout << "yes\n";
  else cout << "no\n";
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