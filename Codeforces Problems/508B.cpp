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
  ll n = s.size();
  char one = s.back();
  ll res = LLONG_MIN,idx=-1;
  for(ll i = 0; i < n-1; i++){
    if(!((s[i]-'0')&1) && (one-'0') > (s[i]-'0')){
      char two = s[i];
      s[i] = one;
      s.back() = two;
      cout << s << endl;
      return;
    }
  }
  for(ll i = n-2; i >= 0; i--){
    if(!((s[i]-'0')&1)){
      char two = s[i];
      s[i] = one;
      s.back() = two;
      cout << s << endl;
      return;
    }
  }
  cout << -1 << endl;
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
  
  solve();
  
}