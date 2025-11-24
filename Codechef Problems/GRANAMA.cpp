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
  string a,b;
  cin >> a >> b;
  bool one = true, two = true;
  map<char, ll> mp1, mp2;
  for(auto el : a) mp1[el]++;
  for(auto el : b) mp2[el]++;

  for(auto el : mp1) if(!mp2[el.first]) one = false;
  if(mp1.size() != mp2.size()) one = false;
  
  if(!one){
    cout << "YES\n";
    return;
  }
  for(auto el : mp1) if(mp2[el.first] != el.second) two = false;
  if(!two){
    cout << "NO\n";
  } else{
    cout << "YES\n";
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