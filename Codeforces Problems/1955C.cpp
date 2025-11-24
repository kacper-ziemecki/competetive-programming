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
  for(auto &el : list) cin >> el;
  ll right = n-1,left = 0,res=0;
  while(k > 1 && left < right){
    ll mn = min({list[left], list[right], k/2});
    list[left] -= mn;
    list[right] -= mn;
    k -= 2*mn;
    if(list[left] == 0){res++; left++; }
    if(list[right] == 0){res++; right--; }
    // dbg(k, left, right);
  }
  if(k > 0 && left==right && list[left] <= k){
    k -= list[left];
    list[left] = 0;
    res++;
  }
  if(k == 1 && (list[left] == 1 || list[right] == 1)) res++; 
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