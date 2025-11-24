#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


vector<ll> p,r;

ll find_set(ll a){
  return (a == p[a] ? a : p[a] = find_set(p[a]));
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(r[a] < r[b]) swap(a, b);
  r[a] += r[b];
  p[b] = a;
}

void solve()
{
  ll n,m,k,a;
  cin >> n >> m;
  p.assign(n+1, 0); r.assign(n+1, 1);
  for(ll i = 0; i < n+1; i++) p[i]=i;
  for(ll i = 0; i < m; i++){
    cin >> k;
    vector<ll> cur(k, 0);
    for(auto &el : cur) cin >> el;
    for(ll i = 1; i < k; i++) union_sets(cur[i], cur[0]);
  }
  for(ll i = 1; i <= n; i++){
    cout << r[find_set(i)] << " ";
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

  solve();  
  
} 