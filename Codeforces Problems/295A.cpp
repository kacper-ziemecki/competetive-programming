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
  ll n,m,k,l,r;
  cin >> n >> m >> k;
  vector<ll> list(n), list1(m+1,0), prefix(m+1,0), list2(n+1, 0), prefix2(n+1, 0);
  vector<vector<ll>> operations(m, vector<ll>(3, 0));
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < m; i++) cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
  for(ll i = 0; i < k; i++){
    cin >> l >> r;
    list1[l-1]++;
    list1[r]--;
  }
  prefix[0] = list1[0];
  for(ll i = 1; i < m; i++) prefix[i] = prefix[i-1] + list1[i];
  for(ll i = 0; i < m; i++) operations[i][2] *= prefix[i];
  for(auto el : operations){
    list2[el[0]-1] += el[2];
    list2[el[1]] -= el[2];
  }
  prefix2[0] = list2[0];
  for(ll i = 1; i < n; i++) prefix2[i] = prefix2[i-1] + list2[i];
  for(ll i = 0; i < n; i++) list[i] += prefix2[i];

  for(auto el : list) cout << el << " ";
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