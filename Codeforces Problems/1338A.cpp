#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n,res=0,ans=0;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  ll mx=list[0];
  for(ll i = 1; i < n; i++){
    if(list[i] < mx) res = max(res, mx-list[i]);
    mx = max(mx, list[i]);
  }
  ll pow=0, sum=0;
  // dbg(res);
  while(sum < res){
    // dbg(pow);
    if(pow) pow <<= 1;
    else pow = 1;
    sum += pow;
    ans++;
  }
  cout << ans << endl;
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