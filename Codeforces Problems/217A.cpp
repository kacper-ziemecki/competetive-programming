#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p(1e6, 0), s(1e6, 1);
ll cnt;

ll find_set(ll v){
  return (p[v] == v ? v : p[v] = find_set(p[v]));
}
void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a != b){
    if(s[a] < s[b]){
      swap(a,b);
    }
    p[b] = a;
    s[a] += b;
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll, ll>> list(n, {0, 0});
  for(auto &el : list) cin >> el.first >> el.second;
  for(ll i = 0; i < n; i++) p[i]=i;
  cnt = n;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      if(list[i].first == list[j].first || list[i].second == list[j].second){
        if(find_set(i) == find_set(j)) continue;
        cnt--;
        union_sets(i, j);
      }
    }
  }
  cout << cnt-1 << endl;
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