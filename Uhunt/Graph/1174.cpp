#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

unordered_map<string, string> p;
unordered_map<string, ll> r;

string findSet(string a){
  return (p[a] == a ? a : p[a] = findSet(p[a]));
}

void unionSet(string a, string b){
  a = findSet(a);
  b = findSet(b);
  if(a == b) return;
  if(r[a] < r[b]) swap(a, b);
  p[b] = a;
  r[a]++;
}

void createSet(string a){
  p[a] = a;
  r[a] = 1;
}

void solve(){
  p.clear();
  r.clear();

  ll n,m;
  cin >> n >> m;
  vector<tuple<ll, string, string>> edges(m);
  for(auto &edge : edges) cin >> get<1>(edge) >> get<2>(edge) >> get<0>(edge);
  sort(edges.begin(), edges.end());

  ll res = 0;
  for(auto edge : edges){
    if(p.count(get<1>(edge)) == 0) createSet(get<1>(edge));
    if(p.count(get<2>(edge)) == 0) createSet(get<2>(edge));
    if(findSet(get<1>(edge)) != findSet(get<2>(edge))){
      unionSet(get<1>(edge), get<2>(edge));
      res += get<0>(edge);
    }
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

  ll t;
  cin >> t;
  while(t--){
    solve();
    if(t != 0) cout << endl;
  }
}