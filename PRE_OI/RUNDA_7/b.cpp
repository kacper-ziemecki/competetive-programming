#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
ll a,v;
ll res = LLONG_MIN;
vector<ll> prev1 = {LLONG_MIN, -1, 0}, prev2 = {LLONG_MIN, -1, 0};
vector<ll> cur1 = {LLONG_MIN, -1, 0};
void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a >> v;
    cur1[0] = max(v,prev1[0]+v);
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}