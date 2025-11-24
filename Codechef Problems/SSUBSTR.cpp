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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  string res(1, s[0]);
  for(ll i = 1; i < n; i++){
    if(s[i] != s[i-1]) res += s[i];
  }
  ll ones = 0, zeros = 0;
  for(auto el : res){
    if(el == '1') ones++;
    else zeros++;
  }
  if(res.front() == '0'){
    cout << (res.back() == '1' ? ones-1 : ones) << endl;
  } else{
    cout << zeros << endl;
  }
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