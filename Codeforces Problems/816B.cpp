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
  ll n,k,q,l,r;
  cin >> n >> k >> q;
  vector<ll> list(200002, 0), prefix_sum1(200002, 0), prefix_sum2(200002, 0);
  for(ll i = 0; i < n; i++){
    cin >> l >> r;
    list[l]++;
    list[r+1]--;
  }
  prefix_sum1[0] = list[0];
  for(ll i=1; i < 200002; i++) prefix_sum1[i] = prefix_sum1[i-1] + list[i];
  prefix_sum2[0] = (prefix_sum1[0] >= k ? 1 : 0);
  for(ll i=1; i < 200002; i++) prefix_sum2[i] = prefix_sum2[i-1] + (prefix_sum1[i] >= k ? 1 : 0);
  for(ll i = 0; i < q; i++){
    cin >> l >> r;
    cout << prefix_sum2[r]-prefix_sum2[l-1] << endl;
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