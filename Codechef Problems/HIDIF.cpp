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
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n);
  ll suma=0,res=0;
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n; i++) suma += abs(list[i] - list[i-1]);
  res = suma;
  for(ll i = 0; i < n; i++){
    if(i == 0){
      ll tmp = suma - abs(list[i] - list[i+1]);
      res = max(res, tmp + abs(list[i+1]-k));
      res = max(res, tmp + abs(list[i+1]-1));
    } 
    else if(i == n-1){
      ll tmp = suma - abs(list[i] - list[i-1]);
      res = max(res, tmp + abs(list[i-1]-k));
      res = max(res, tmp + abs(list[i-1]-1));
    }
    else{
      ll tmp = suma - abs(list[i] - list[i-1]) - abs(list[i] - list[i+1]);
      res = max(res, tmp + abs(list[i-1]-k) + abs(list[i+1]-k));
      res = max(res, tmp + abs(list[i-1]-1) + abs(list[i+1]-1));
    }
    // dbg(res);
  }
  cout << res << endl;
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