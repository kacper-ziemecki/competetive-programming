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
  vector<ll> list;
  if(s[0] == '.') list.push_back(1);
  for(ll i = 1; i < n; i++){
    if(s[i] == '.' && s[i] == s[i-1]){
      list[list.size()-1]++;
    } else if(s[i] == '.' && s[i] != s[i-1]){
      list.push_back(1);
    }
  }
  ll maks = 0, res = 0;
  for(auto el : list){
    if(el > maks){
      maks = el;
      res++;
    }
  }
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