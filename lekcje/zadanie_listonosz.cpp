#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
ll iter = 0;

void dfs(ll u, map<ll, vector<ll>>& adj, map<pair<ll,ll>,bool>& vis, map<pair<ll,ll>, vector<ll>>& replacement, vector<ll>& euler, vector<ll> tmp = {}){
  for(auto v : adj[u]){
    if(!vis[{u,v}]){
      vis[{u,v}] = true;
      if(replacement.count({u,v})) dfs(v,adj,vis,replacement,euler,replacement[{u,v}]);
      else dfs(v,adj,vis,replacement,euler);
    }
  }
  if(!tmp.empty()){
    for(ll i = tmp.size()-1; i >= 1; i--) euler.pb(tmp[i]);
  }
  else euler.pb(u);
}

string print(pair<ll,ll>& a){
  return "(" + to_string(a.first) + ", " + to_string(a.second) + ")";
}

void solve()
{
ll n,m,q,k,cnt=1;
cin >> n >> m;
set<pair<ll,ll>> edges;
vector<vector<ll>> lists;
map<pair<ll,ll>, ll> id;
map<ll, pair<ll,ll>> reverse_id;
map<ll, vector<ll>> adj2,adj;
map<pair<ll,ll>, vector<ll>> replacement;
map<ll,ll> in_deg,out_deg;
map<pair<ll,ll>, bool> vis;
vector<ll> list;
ll u,v;
for(ll i = 0; i < m; i++){
  cin >> u >> v;
  edges.emplace(u,v);
}
cin >> q;

for(ll i = 0; i < q; i++){
  cin >> k;
  list.assign(k,0);
  for(ll j = 0; j < k; j++) cin >> list[j];
  lists.pb(list);
}
for(ll i = 0; i < q; i++){
  for(ll j = 2; j < lists[i].size(); j++){
    if(!edges.count({lists[i][j-2], lists[i][j-1]}) || !edges.count({lists[i][j-1], lists[i][j]})){ cout << "NIE\n"; return; }
    
    if(!id.count({lists[i][j-2], lists[i][j-1]})){
      reverse_id[cnt] = {lists[i][j-2], lists[i][j-1]};
      id[{lists[i][j-2], lists[i][j-1]}] = cnt++;
    }
    if(!id.count({lists[i][j-1], lists[i][j]})){
      reverse_id[cnt] = {lists[i][j-1], lists[i][j]};
      id[{lists[i][j-1], lists[i][j]}] = cnt++;
    }
    adj2[id[{lists[i][j-2], lists[i][j-1]}]].pb(id[{lists[i][j-1], lists[i][j]}]);
  }
}
vector<ll> in_deg2(cnt),out_deg2(cnt);
for(ll u = 1; u < cnt; u++){
  edges.erase(reverse_id[u]);
  for(auto v : adj2[u]){
    in_deg2[v]++; out_deg2[u]++;
    if(in_deg2[v] > 1 || out_deg2[u] > 1){ cout << "NIE\n"; return; }
  }
} 
// for(auto [u, children] : adj2){
//   cout << print(reverse_id[u]) << " -> ";
//   for(auto v : children) cout << print(reverse_id[v]) << " ";
//   cout << endl;
// }
for(ll u = 1; u < cnt; u++){
  if(in_deg2[u] == 0){
    vector<ll> tmp;
    ll cur = u;
    while(out_deg2[cur]){
      // dbg(cur, print(reverse_id[cur]));
      tmp.pb(reverse_id[cur].first);
      cur = adj2[cur][0];
    }
    tmp.pb(reverse_id[cur].first);
    tmp.pb(reverse_id[cur].second);
    replacement[{tmp.front(), tmp.back()}] = tmp;
    edges.emplace(tmp.front(), tmp.back());
    // for(auto el : tmp) cout << el << " ";
    // cout << endl;
  }
  }
  for(auto edge : edges){
    adj[edge.first].pb(edge.second);
    out_deg[edge.first]++; in_deg[edge.second]++;
    // cout << print(edge) << " ";
  }
  // cout << endl;
  // for(auto el : adj){
  //   cout << el.first << " -> ";
  //   for(auto el1 : el.second) cout << el1 << ", ";
  //   cout << endl;
  // }

  for(auto edge : edges){
    if(out_deg[edge.first] != in_deg[edge.first]){ cout << "NIE\n"; return; }
    if(out_deg[edge.second] != in_deg[edge.second]){ cout << "NIE\n"; return; }
  }

  vector<ll> euler;
  dfs(1, adj, vis, replacement, euler);
  reverse(euler.begin(), euler.end());
  cout << "TAK\n";
  for(auto el : euler) cout << el << endl;
}


int main()
{

ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

solve();
}