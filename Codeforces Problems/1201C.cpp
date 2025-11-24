#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(vector<ll> &list, ll mid, ll k, ll n){
  for(ll i = n/2; i < n; i++){
    
  }
}

void solve(){
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  list.push_back(LLONG_MAX);
  sort(list.begin(), list.end());
  ll l=0,r=k;
  while(l < r){
    ll mid = (l+r+1)/2;
    if(check(list, mid, k, n)) l = mid;
    else r = mid-1;
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
  
  solve();
}