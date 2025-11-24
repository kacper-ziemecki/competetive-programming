#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll truncate(string s){
  while(s.back() < '0' || s.back() > '9') s.erase(s.size()-1);
  return stoll(s);
}
vector<ll> p,r;
ll findSet(ll a){ return (a == p[a] ? a : p[a] = findSet(p[a])); }
void unionSet(ll a, ll b){
  a = findSet(a);
  b = findSet(b);
  if(a == b) return;
  if(r[a] < r[b]) swap(a, b);
  p[b] = a;
  r[a]++;
}
void solve(){
  ll n;
  cin >> n;
  p.assign(n+1, 1);
  r.assign(n+1, 1);
  for(ll i = 0; i <= n; i++) p[i]=i;
  string s;
  vector<tuple<ll, ll, ll>> edges;
  for(ll i = 0; i < n; i++){
    stringstream stream;
    string s2;
    getline(cin >> ws, s);
    stream << s;
    for(ll j = 0; j < n; j++){
      stream >> s2;
      ll w = truncate(s2);
      if(w) edges.push_back({w, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  for(auto edge : edges){
    if(findSet(get<1>(edge)) != findSet(get<2>(edge))){
      unionSet(get<1>(edge), get<2>(edge));
      cout << char(get<1>(edge)+'A') << "-" << char(get<2>(edge)+'A') << " " << get<0>(edge) << endl;
    }
  }
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
    cout << "Case " << i << ":\n";
    solve();
  }
}