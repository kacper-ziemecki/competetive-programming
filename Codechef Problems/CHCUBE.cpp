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
  vector<string> list(6);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i <= 1; i++){
    for(ll j = 2; j <= 3; j++){
      for(ll k = 4; k <= 5; k++){
        if(list[i] == list[j] && list[j] == list[k]){
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
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