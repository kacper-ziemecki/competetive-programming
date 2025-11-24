#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(ll n){
  vector<vector<ll>> list(n, vector<ll>(n));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++) cin >> list[i][j];
  }
  for(ll i = 0; i < (n+1)/2; i++){
    if(i!=0) cout << " ";
    ll res=0;
    for(ll j = i; j < n-i; j++) res += list[i][j];
    for(ll j = i+1; j < n-i; j++) res += list[j][n-i-1];
    for(ll j = i; j < n-i-1; j++) res += list[n-i-1][j];
    for(ll j = i+1; j < n-i-1; j++) res += list[j][i];
    cout << res;
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
  
  ll n;
  ll t=0;
  while(cin >> n, n != 0){
    cout << "Case " << ++t << ": ";
    solve(n);
  }
}