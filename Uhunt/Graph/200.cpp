#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void helper(ll left, ll right, ll index, ll n, vector<string> &list, vector<string> &order){
  if(index >= n) return;
  string tmp;
  if(list[index][left] != ' ') tmp += list[index][left];
  ll cnt=1;
  for(ll i = left+1; i < right; i++){
    if(list[index][i] == list[index][i-1]){ cnt++; continue; }
    else{
      if(cnt > 1) helper(i-cnt, i, index+1, n, list, order);
      cnt=1;
      if(list[index][i] != ' ') tmp += list[index][i];
    }
  }
  if(cnt > 1) helper(right-cnt, right, index+1, n, list, order);
  // cout << tmp << endl;
  order.push_back(tmp);
}

void toposort(char u, map<char, vector<char>> &adj, map<char, bool> &vis, vector<char> &topo){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) toposort(v, adj, vis, topo);
  }
  topo.push_back(u);
}

void solve(){
  string a;
  ll n=0,m=0;
  vector<string> list1, list2;
  vector<string> order;
  map<char, bool> vis;
  map<char, vector<char>> adj;
  map<char, bool> znajdujemy_z;
  while(cin >> a, a != "#"){
    list1.push_back(a);
    for(auto el : a) znajdujemy_z[el] = true;
    n++;
    m = max(m, (ll)a.size());
  }
  list2.assign(m, string(n, ' '));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < list1[i].size(); j++){
      list2[j][i] = list1[i][j];
    }
  }
  // for(string el : list2) cout << el << endl;
  helper(0, n, 0, m, list2, order);
  for(string sub : order){
    vis[sub[0]] = false;
    for(ll i = 1; i < sub.size(); i++){
      adj[sub[i-1]].push_back(sub[i]);
      vis[sub[i]] = false;
    }
  }
  // for(pair<char, vector<char>> sub : adj){
  //   cout << sub.first << " : ";
  //   for(auto el : sub.second) cout << el << " ";
  //   cout << endl;
  // }
  vector<char> topo;
  for(auto u : znajdujemy_z){
    if(!vis[u.first]) toposort(u.first, adj, vis, topo);
  }
  reverse(topo.begin(), topo.end());
  for(auto el : topo) cout << el;
  cout << endl;
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

  solve();
}