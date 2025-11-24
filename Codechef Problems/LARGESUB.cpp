#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool correct(string s){
  ll a=0,b=0;
  for(ll i = 1; i < s.size(); i++){
    if(s[i-1] == 'a' && s[i] == 'b') a++;
    if(s[i-1] == 'b' && s[i] == 'a') b++;
  }
  return a==b;
}

void solve(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll one = 0, two = n-1;
  for(ll i = 1; i < n; i++){
    one = i;
    if(s[i] != s[i-1]) break;
  }
  for(ll i = n-2; i >= 0; i--){
    two = i;
    if(s[i] != s[i+1]) break;
  }
  // dbg(one, two);
  // dbg(s.substr(one, n-one));
  // dbg(s.substr(0, two+1));
  ll res = 0;
  if(correct(s)) res = max(res, n);
  if(correct(s.substr(one, n-one))) res = max(res, n-one);
  if(correct(s.substr(0, two+1))) res = max(res, two+1);
  cout << res << endl;
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