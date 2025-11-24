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
vector<pair<ll, ll>> list(1e6, {0, 0});

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
    list[a].second = b;
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<pair<string, string>> list(n, {" ", " "});
  for(auto &el : list) cin >> el.first >> el.second;
  map<string, ll> m;
  map<string, bool> m2;
  for(ll i = 0; i < 2*n; i+=2){
    m[list[i/2].first] = i;
    m[list[i/2].second] = i+1;
  }
  for(ll i = 0; i < 2*n; i++){
    p[i] = i;
    list[i] = {i, i};
  }
  for(ll i = 0; i < n; i++){
    if(!m2[list[i].second]){
      m2[list[i].second] = true;
      m2[list[i].first] = true;
      union_sets(m[list[i].first], m[list[i].second]);
    }
  }
  for(ll i = 0; i < n; i++){
    cout << 
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