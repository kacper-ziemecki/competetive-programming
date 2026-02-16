#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
vector<pair<int,int>> nodes;
string s;

struct DSU{
  vector<int> p, sajz;
  DSU(int n){
    sajz.assign(n+1,1);
    p.resize(n+1);
    for(int i = 0; i <= n; i++) p[i]=i;
  }
  int findSet(int a){
    return (p[a] == a ? a : p[a] = findSet(p[a])); 
  }
  void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
};

void solve(){
  cin >> n;
  DSU dsu(n+1);
  set<int> roots;
  for(int i = 0; i < n; i++){
    cin >> s;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int node = 0;
    int j = 0;
    for(char c = 'a'; c <= 'z'; c++){
      if(s[j] == c){
        node += 1<<(c-'a');
        j++;
      }
      if(j >= s.size()) break;
    }
    nodes.pb(make_pair(nodes.size(),node));
  }
  for(char c = 'a'; c <= 'z'; c++){
    int pierwszy = -1;
    for(int i = 0; i < n; i++){
      if((nodes[i].second)&(1<<(c-'a')) && (pierwszy == -1)){
        pierwszy = nodes[i].first;
      } 
      else if((nodes[i].second)&(1<<(c-'a')) && (pierwszy != -1)){
        dsu.unionSet(pierwszy, nodes[i].first);
      }
    }
  }
  int res=0;
  for(int i = 0; i < n; i++){
    if(roots.count(dsu.findSet(nodes[i].first))) continue;
    res++;
    roots.emplace(dsu.findSet(nodes[i].first));
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

  solve();
}