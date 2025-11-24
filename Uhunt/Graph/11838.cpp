#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
vector<vector<ll>> adj,adj_inv;

void solve(ll n, ll m){
  ll a,b,c;
  adj.resize(n+1);
  adj_inv.resize(n+1);
  for(ll i = 0; i < m; i++){
    cin >> a >> b >> c;
    if(a == 1)
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
  
  ll n,m;
  cin >> n >> m;
  while(n != 0 && m != 0){
    solve(n,m);
    cin >> n >> m;
  }
}