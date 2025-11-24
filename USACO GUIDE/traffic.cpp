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
  ll n,a,b;
  string s;
  cin >> n;
  vector<tuple<string, ll, ll>> l(n, {"", 0ll, 0ll});
  for(ll i = 0; i < n; i++){
    cin >> s >> a >> b;
    get<0>(l[i]) = s;
    get<1>(l[i]) = a;
    get<2>(l[i]) = b;
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