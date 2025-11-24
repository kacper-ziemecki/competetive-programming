#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void helper(vector<string> &res, map<char, string> &adj, map<char, ll> &in_degree, set<char> &st, string tmp = "", char erase = ' '){
  // dbg(st.size());
  // dbg(erase);
  if(erase != ' ') st.erase(erase);
  if(st.empty()){ res.push_back(tmp);}
  // dbg(st.size());
  // for(auto u : st) cout << u << " ";
  // cout << endl;
  // dbg(tmp);
  for(char u : st){
    set<char> st1 = st;
    for(char v : adj[u]){
      if(--in_degree[v] == 0) st1.emplace(v);
      // cout << v << " -> " << in_degree[v] << endl;
    }

    helper(res, adj, in_degree, st1, tmp+u, u);

    for(auto v : adj[u]) in_degree[v]++;
  }
  if(erase != ' ') st.emplace(erase);
}

void solve(string a, string b){
  stringstream one,two;
  one << a;
  two << b;
  map<char, string> adj;
  map<char, ll> in_degree;
  vector<string> res;
  set<char> st;
  char u,v;
  while(one >> u) adj[u] = "";
  while(two >> u >> v){ adj[u] += v; in_degree[v]++; }
  for(auto el : adj){ if(!in_degree[el.first]) st.emplace(el.first); }
  helper(res, adj, in_degree, st);

  // for(auto el : adj){
  //   cout << el.first << " : " << el.second << endl;
  // }
  sort(res.begin(), res.end());
  for(auto el : res) cout << el << endl;
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


  string a, b;
  getline(cin, a);
  getline(cin, b);
  ll cnt = 0;
  while(!a.empty() && !b.empty()){
    cnt++;
    if(cnt > 1) cout << endl;
    solve(a, b);
    a.clear();
    b.clear();
    getline(cin, a);
    getline(cin, b);
  }
}