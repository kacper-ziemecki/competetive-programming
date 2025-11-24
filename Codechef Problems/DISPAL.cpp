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
  ll n,x;
  cin >> n >> x;
  if(x > (n+1)/2){
    cout << -1 << endl;
    return;
  }
  string res;
  for(ll i = 0; i < x; i++){
    res += char('a'+i);
  }
  for(ll i = x; i < (n+1)/2; i++){
    res += 'a';
  }
  string tmp;
  if(n&1) tmp = res.substr(0, res.size()-1);
  else tmp = res;
  reverse(tmp.begin(), tmp.end());
  cout << res + tmp << endl;
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