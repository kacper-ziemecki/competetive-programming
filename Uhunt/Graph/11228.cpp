#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ld distance(pair<ld,ld>& a, pair<ld,ld>& b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
vector<ll> p,r;
ll findSet(ll a){
  return (a == p[a] ? a : p[a] = findSet(p[a]));
}
void unionSet(ll a,ll b){
  a = findSet(a);
  b = findSet(b);
  if(a == b) return;
  if(r[a] < r[b]) swap(a, b);
  p[b] = a;
  r[a]++;
}

void solve(){
  ll n,k;
  cin >> n >> k;
  p.assign(n, 1);
  r.assign(n, 1);
  for(ll i = 0; i < n; i++) p[i]=i;
  vector<pair<ld,ld>> list(n);
  for(auto &el : list) cin >> el.first >> el.second;
  vector<tuple<ld,ld,ld>> edges;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      edges.push_back({distance(list[i], list[j]), i, j});
    }
  }
  sort(edges.begin(), edges.end());
  ld res1=1,res2=0,res3=0;
  for(auto edge : edges){
    if(findSet(get<1>(edge)) != findSet(get<2>(edge))){
      unionSet(get<1>(edge), get<2>(edge));
      if(get<0>(edge) > k){
        res1++;
        res3 += get<0>(edge);
      } else{
        res2 += get<0>(edge);
      }
    }
  }
  cout << res1 << " " << round(res2) << " " << round(res3) << endl;
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

  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }
}