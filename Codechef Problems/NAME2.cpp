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
  ll i = 0;
  for(ll j = 0; j < a.size(); j++){
    if(i < b.size() && b[i] == a[j]) i++;
  }
  if(i == b.size()){
    cout << "YES\n";
    return;
  }
  i = 0;
  for(ll j = 0; j < b.size(); j++){
    if(i < a.size() && a[i] == b[j]) i++;
  }
  if(i == a.size()){
    cout << "YES\n";
    return;
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