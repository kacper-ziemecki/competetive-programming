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
  string s,res;
  cin >> n >> s;
  for(auto el : s){
    if(el == '2') res += '2';
    else if(el == '3') res += '3';
    else if(el == '4') res += "322";
    else if(el == '5') res += '5';
    else if(el == '6') res += "53";
    else if(el == '7') res += '7';
    else if(el == '8') res += "7222";
    else if(el == '9') res += "7332";
  }
  sort(res.begin(),res.end(),greater<>());
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
  
  solve();
}