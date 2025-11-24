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
  ll n,res=0;
  cin >> n;
  string s;
  cin >> s;
  bool flag1 = false;
  bool flag2 = false;
  for(auto el : s){
    if(el == ':' && !flag1){
      flag1 = true;
      flag2 = false;
    }
    if(el == ':' && flag && !flag){
      
    }
    if(el == ':' && flag1 && flag2){
      res++;
      flag2 = false;
    }
    if(el == ')' && flag1){
      flag2 = true;
    }
    if(el == ')' && !flag1){
      flag1 = false;
    }
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