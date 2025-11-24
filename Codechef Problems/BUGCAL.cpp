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
  string a,b,c="";
  cin >> a >> b;
  for(ll i = 0; i < min(a.size(), b.size()); i++){
    c += char(((a[a.size()-1-i]-'0')+(b[b.size()-1-i]-'0'))%10 + '0');
  }
  for(ll i = max(a.size(), b.size()) - min(a.size(), b.size())-1; i >= 0; i--){
    if(a.size() >= b.size()){
      c += a[i];
    } else{
      c += b[i];
    }
  }
  reverse(c.begin(), c.end());
  ll cnt = 0;
  for(ll i = 0; i < c.size(); i++){
    if(c[i] != '0') break;
    cnt++;
  }
  if(cnt == c.size()) cout << 0 << endl;
  else cout << c.substr(cnt, c.size()-cnt) << endl;
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