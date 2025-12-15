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
  string res = "";
  vector<ll> one,two;
  vector<bool> list(s.size(), true);
  ll x = -1;
  for(auto el : s){
    if(el == 'b'){
      if(!one.empty()){
        list[one.back()] = false;
        one.pop_back();
      }
    } else if(el == 'B'){
        if(!two.empty()){
          list[two.back()] = false;
          two.pop_back();
        }
    } else{
      x++;
      res += el;
      if(tolower(el) == el){
        one.push_back(x);
      } else{
        two.push_back(x);
      }
    }
  }
  for(ll i = 0; i < res.size(); i++){
    if(list[i]) cout << res[i];
  }
  cout << endl;
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