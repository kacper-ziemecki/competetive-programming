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
  ll n,k,res=0;
  cin >> n >> k;
  vector<ll> list(n);
  vector<ll> ans;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    if(list[i] < 0){
      res++;
      ans.push_back(i+1);
      if(i+1 < n) list[i+1] = -list[i+1]; 
    }
  }
  cout << res << endl;
  for(auto el : ans) cout << el << " ";
  cout << endl;
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

  
  solve();
  
  
}