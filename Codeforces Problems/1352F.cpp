#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll a,b,c;
  cin >> a >> b >> c;
  for(ll i = 0; i < (a == 0 && b == 0 ? 0 : a+1); i++) cout << '0';
  for(ll i = 0; i < (b == 0 && c == 0 ? 0 : c+1); i++) cout << '1';
  for(ll i = 0; i < b-1; i++){
    if(i&1) cout << '1';
    else cout << '0';
  }
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

  ll t;
  cin >> t;
  while(t--)
    solve();
}