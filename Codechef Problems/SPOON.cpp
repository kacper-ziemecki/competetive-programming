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
  ll n,m;
  cin >> n >> m;
  vector<string> list(n, string(m, ' '));
  string s = "spoon";
  for(auto &el : list) cin >> el; 
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(n-i >= s.size()){
        bool flag = true;
        for(ll k = 0; k < s.size(); k++){
          if(char(tolower(list[i+k][j])) != s[k]) flag = false;
        }
        if(flag){
          cout << "There is a spoon!\n";
          return;
        }
      }
      if(m-j >= s.size()){
        bool flag = true;
        for(ll k = 0; k < s.size(); k++){
          if(char(tolower(list[i][j+k])) != s[k]) flag = false;
        }
        if(flag){
          cout << "There is a spoon!\n";
          return;
        }
      }
    }
  }
  cout << "There is indeed no spoon!\n";
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