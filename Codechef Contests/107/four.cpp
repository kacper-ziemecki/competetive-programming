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
  ll n;
  cin >> n;
  string text;
  cin >> text;
  vector<ll> list{1ll};
  for(ll i = 1; i < n; i++){
    if(text[i] != text[i-1]){
      list.push_back(1ll);
    } else{
      list.back()++;
    }
  } 
  bool one = true, zero = true;
  for(ll i = 0; i < list.size(); i++){
    if(i&1){
      if(list[i]&1) one=false;
    } else{
      if(list[i]&1) zero=false;
    }
  }
  bool res = one || zero;
  if(res){
    cout << "Yes\n";
  } else{
    cout << "No\n";
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