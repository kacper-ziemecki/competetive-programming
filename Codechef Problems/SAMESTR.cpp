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
  ll zeros=0,ones=0;
  for(auto el : s){
    if(el == '0') zeros++;
    else ones++;
  }
  set<ll> res;
  while(zeros <= n){
    if(zeros >= 1) res.emplace(zeros);
    zeros+=2;
  }
  while(ones <= n){
    if(ones >= 1) res.emplace(ones);
    ones+=2;
  }
  cout << res.size() << endl;
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