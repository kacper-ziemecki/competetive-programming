#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,k,p;
const ll N = 1001;
const ll K = 2001;

ll lista1[N];
ll lista2[N];

ull koszt[N][K];

void solve()
{
  cin >> n >> k >> p;
  for(int i = 0; i < n; i++) cin >> lista1[i];
  for(int i = 0; i < k; i++) cin >> lista2[i];
  sort(lista1, lista1+n);
  sort(lista2, lista2+k);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      koszt[i][j] = llabs(lista1[i]-lista2[j])+llabs(lista2[j]-p);
    }
  }
  ull res = LLONG_MAX;
  for(ll i = 0; i+n-1 < k; i++){
    ull cur = 0;
    for(int j = 0; j < n; j++){
      cur = max(cur, koszt[j][i+j]);
    }
    res = min(res, cur);
  }
  cout << res << endl;
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

  solve();

}