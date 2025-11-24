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
  ll n;
  cin >> n;
  vector<vector<ll>> res(n, vector<ll>(n, 0));

  ll cnt = 1;
  for(ll i = 0; i < n; i+=2){
    for(ll j = 0; j < n; j++){
      res[(i+j)%n][j] = cnt;
    }
    cnt++;
  }
  cnt = n;
  for(ll i = 0; i < n; i+=2){
    for(ll j = 0; j < n; j++){
      res[n-1-j][(i+j)%n] = cnt;
    }
    cnt--;
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++) cout << res[i][j] << " ";
    cout << endl;
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