#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll cost(string a, string b){
  ll res = 0;
  for(ll i = 0; i < a.size(); i++){
    ll one = a[i]-'0', two = b[i]-'0';
    res += min({abs(one-two), one+(9-two+1), two+(9-one+1)});
  }
  return res;
}

unordered_map<string, string> p;
unordered_map<string, ll> r;
string findSet(string a){
  return (a == p[a] ? a : p[a] = findSet(p[a]));
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
  p[a]=a;
  r[a]=1;
}

void solve(){
  p.clear();
  r.clear();

  ll n;
  cin >> n;
  vector<string> list(n);
  vector<tuple<ll, string, string>> edges;
  for(auto &el : list) cin >> el;
  list.push_back("0000");
  for(ll i = 0; i < n+1; i++){
    for(ll j = i+1; j < n+1; j++){
      dbg(cost(list[i], list[j]), list[i], list[j]);
      edges.push_back({cost(list[i], list[j]), list[i], list[j]});
    }
  }
  sort(edges.begin(), edges.end());
  ll res=0;
  for(auto edge : edges){
    if(p.count(get<1>(edge)) == 0) createSet(get<1>(edge));
    if(p.count(get<2>(edge)) == 0) createSet(get<2>(edge));
    if(findSet(get<1>(edge)) != findSet(get<2>(edge))){
      // dbg(get<1>(edge), get<2>(edge), get<0>(edge));
      res += get<0>(edge);
      unionSet(get<1>(edge), get<2>(edge));
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
  while(t--) solve();
}