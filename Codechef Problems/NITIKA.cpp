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
  getline(cin >> ws, s);
  vector<string> list{""};
  for(auto el : s){
    if(el != ' ') list.back() += el;
    else list.push_back("");
  }
  for(ll i = 0; i < list.size(); i++){
    if(i == list.size()-1){
      for(ll j = 0; j < list[i].size(); j++){
        if(j == 0) cout << char(toupper(list[i][j]));
        else cout << char(tolower(list[i][j]));
      }
      cout << endl;
    } else{
      cout << char(toupper(list[i][0])) << ". ";
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