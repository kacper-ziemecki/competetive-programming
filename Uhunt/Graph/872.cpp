#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void helper(map<char, vector<char>> &adj, map<char, ll> &in_degree, vector<unordered_set<char>> &res, set<char> &st, unordered_set<char> &tmp, ll n){
  if(tmp.size() == n) res.push_back(tmp);
  for(char u : st){
    set<char> st1 = st;
    st1.erase(u);
    tmp.emplace(u);
    for(char v : adj[u]) if(--in_degree[v] == 0) st1.emplace(v);
    helper(adj, in_degree, res, st1, tmp, n);
    tmp.erase(u);
    for(char v : adj[u]) in_degree[v]++;
  }
}

void solve(){
  string a,b,tmp;
  char u;
  stringstream c,d;
  getline(cin >> ws, a);
  getline(cin >> ws, b);
  c << a;
  d << b;
  map<char, vector<char>> adj;
  map<char, ll> in_degree;
  vector<unordered_set<char>> res;
  set<char> st;
  unordered_set<char> temporary;
  while(!c.eof()){
    c >> u;
    adj[u] = {};
    in_degree[u] = 0;
  }
  while(!d.eof()){
    d >> tmp;
    adj[tmp[0]].push_back(tmp[2]);
    in_degree[tmp[2]]++;
  }
  for(pair<char, ll> el : in_degree) if(el.second == 0) st.emplace(el.first);
  helper(adj, in_degree, res, st, temporary, adj.size());
  if(res.empty()){
    cout << "NO\n";
  }
  vector<vector<char>> ans;
  for(auto &sub : res){
    vector<char> r;
    for(auto el : sub) r.push_back(el);
    reverse(r.begin(), r.end());
    ans.push_back(r);
  }
  sort(ans.begin(), ans.end());
  for(auto sub : ans){
    for(auto el : sub) cout << el << " ";
    cout << endl;
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

  ll t,i=0;
  cin >> t;
  while(t--){
    i++;
    if(i > 1) cout << endl;
    solve();
  }
}