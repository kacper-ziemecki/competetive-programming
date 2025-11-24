#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll k,l1,r1,l2,r2,res=0;
  cin >> k >> l1 >> r1 >> l2 >> r2;
  res = max(0ll, min(r1,r2)-max(l1,l2)+1);
  while(r2){
    r2 /= k;
    l2 = (l2+k-1)/k;
    ll tmp = min(r1,r2)-max(l1,l2)+1;
    res += max(0ll,tmp);
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