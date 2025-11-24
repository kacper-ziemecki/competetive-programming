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
  if(s[0] == s[1]){
    cout << "NO\n";
    return;
  }
  for(ll i = 2; i < s.size(); i++){
    if(i&1 && s[i] != s[1]){
      cout << "NO\n";
      return;
    }
    if(!(i&1) && s[i] != s[0]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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