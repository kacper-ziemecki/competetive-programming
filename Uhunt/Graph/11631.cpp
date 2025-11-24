#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


vector<ll> p,r;
ll findSet(ll a){
  return (p[a] == a ? a : p[a] = findSet(p[a]));
}
void unionSet(ll a,ll b){
  a = findSet(a);
  b = findSet(b);
  if(a == b) return;
  if(r[a] < r[b]) swap(a, b);
  p[b] = a;
  r[a]++;
}
void setUpDSU(ll n){
  p.assign(n+1, 1);
  r.assign(n+1, 1);
  for(ll i = 0; i <= n; i++) p[i]=i;
}
void solve(ll m,ll n){
  vector<tuple<ll,ll,ll>> edges(n);
  for(auto &el : edges) cin >> get<1>(el) >> get<2>(el) >> get<0>(el);
  sort(edges.begin(), edges.end());
  ll res=0,total=0;
  setUpDSU(m);
  for(auto el : edges){
    total += get<0>(el);
    if(findSet(get<1>(el)) != findSet(get<2>(el))){
      unionSet(get<1>(el), get<2>(el));
      res += get<0>(el);
    }
  }
  cout << total-res << endl;
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

  ll n,m;
  while(cin >> m >> n, n != 0 || m != 0){
    solve(m,n);
  }
}