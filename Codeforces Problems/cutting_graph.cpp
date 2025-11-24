#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p, _size;

ll find_set(ll a){
  return (p[a] == a ? a : p[a] = find_set(p[a]));
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
}

void solve()
{
  ll n,m,k;
  cin >> n >> m >> k;
  ll u,v;
  for(ll i = 0; i < m; i++) cin >> u >> v;
  string s;

  p.assign(n+1, 0); _size.assign(n+1, 0);
  for(ll i = 0; i < n+1; i++) p[i] = i;

  vector<tuple<string, ll, ll>> list(k);
  for(ll i = 0; i < k; i++){
    cin >> s >> u >> v;
    list[i] = {s,u,v};
  }
  reverse(list.begin(), list.end());
  vector<string> res(k);
  ll j = 0;
  for(ll i = 0; i < k; i++){
    s = get<0>(list[i]);
    u = get<1>(list[i]);
    v = get<2>(list[i]);
    if(s == "ask"){
      res[j++] = (find_set(u) == find_set(v) ? "YES\n" : "NO\n");
    } else{
      union_sets(u,v);
    }
  }
  reverse(res.begin(), res.end());
  for(auto el : res) cout << el;
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