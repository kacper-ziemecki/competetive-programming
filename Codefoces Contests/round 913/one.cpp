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
  string s;
  cin >> s;
  string one = "abcdefgh", two="12345678";
  for(auto el : two){
    if(el != s[1]){
      cout << s[0] << el << endl;
    }
  }
  for(auto el : one){
    if(el != s[0]){
      cout << el << s[1] << endl;
    }
  }
}
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
 
  ll t;
  cin >> t;
  while(t--)
  solve();
}