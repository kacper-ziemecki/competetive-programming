#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
int u,v,w;
const int maxn = 1e6+1;
vector<pair<int,int>> adj[maxn]; // adjecency list po angielsku - lista sąsiedztwa
vector<vector<int>> edges; // lista krawedzi 

vector<pair<int,int>> mst[maxn];

struct DSU{
  vector<int> p, sajz;
  DSU(int n){ // n to jest ilosc wierzcholkow w moim dsu
    p.resize(n+1);
    sajz.assign(n+1, 1);
    for(int i = 0; i <= n; i++) p[i] = i;
  }
  int getSet(int a){
    return (p[a] == a ? a : p[a] = getSet(p[a]));
  }
  void unionSet(int a, int b){
    a = getSet(a);
    b = getSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool isCycle(int a, int b){ 
  // jest w tym samym zbiorze i chcemy jeszcze dodać krawędź pomiedzy a i b
  // to wtedy powstanie cykl
    a = getSet(a);
    b = getSet(b);
    return a == b;
  }
};

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../in.in", "r", stdin);
  freopen("../../../out.out", "w", stdout);
#endif

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }
  cout << "ZWYKLY GRAF: \n";
  for(int u = 1; u <= n; u++){
    cout << u << " -> ";
    for(auto _do : adj[u]){
      cout << "{" << _do.first << ", " << _do.second << "} ";
    }
    cout << endl;
  }
  cout << endl;
  for(int u = 1; u <= n; u++){
    for(pair<int,int> _do : adj[u]){
      edges.pb({_do.second,u,_do.first});
      //        waga        u---->v
    }
  }
  // edges -> lista krawędzi
  // edges.size() => m - ilosc krawedzi
  // edges => {{w1,u1,v1},{w2,u2,v2},{w3,u3,v3}...}

  // Tak naprawde algorytm zaczyna się od tąd
  sort(edges.begin(), edges.end());
  // waga1 <= waga2 <= waga3 <= waga4 <= ... <= wagan

  int liczba = 5;
  DSU dsu(n+1);
  for(auto edge : edges){
    w = edge[0]; // waga
    u = edge[1]; // u --> v
    v = edge[2];
    if(!dsu.isCycle(u,v)){ 
    // u i v jescze nie są połączone, to znaczy, 
    // że krawędź, która jest teraz ma wagę która 
    // jest najmniejsza aby połączyć te dwa wierzchołki
      dsu.unionSet(u, v);
      mst[u].pb(make_pair(v, w));
      mst[v].pb(make_pair(u, w));
    }
  }


  cout << "MST: \n";
  for(int u = 1; u <= n; u++){
    cout << u << " -> ";
    for(auto _do : mst[u]){
      cout << "{" << _do.first << ", " << _do.second << "} ";
    }
    cout << endl;
  }
}