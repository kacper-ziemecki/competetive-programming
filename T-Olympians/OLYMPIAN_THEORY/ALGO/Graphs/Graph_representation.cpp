#include <bits/stdc++.h>
using namespace std;




int main()
{

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  //1. adjecency list - lista sąsiedztwa [adj]
  // n - liczba wierzchołków
  // m - liczba krawędzi

  // n m 
  // u1 v1
  // u2 v2
  // u3 v3
  // ...
  // ..
  // .
  // um vm

  // 4 5
  // 0 3
  // 2 3
  // 1 2
  // 0 2
  // 1 3
  // graf skierowany
  // mamy droge
  // 0 --> 3
  // nie mamy 
  // 3 --> 0

  // graf nieskierowany
  // mamy obie drogi
  // 0 --> 3
  // 3 --> 0

  // {
  //   0 {5,4}
  //   1 {3,7}
  //   2 {8}
  //   3 {1, 7}
  //   4 {5}
  //   5 {7,8,100,101, 34,54,46,47,3,224,23,34}
  //   ...
  //   .
  //   .
  //   .
  // }

  // adj[3] = {1,7}
  // 3-->1
  // 3-->7
  for(int v : adj[u]){
    
  }

  int n,m;
  int u,v;
  const int maxn = 100;
  vector<int> adj[maxn];
  for(int i = 0; i < m; i++){
    cin >> u >> v;

    // graf jest nieskierowany
    adj[u].push_back(v);
    adj[v].push_back(u);

    // graf jest skierowany
    adj[u].push_back(v);
  }

  //2. lista krawędzi (edges)

  // {{u1, v1}, {u2, v2}, ...}

  // {{0, 3}, {2, 3}, ...}

  vector<pair<int,int>> edges;
  int n,m;
  int u,v;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    edges.push_back(make_pair(u,v));
  }

  //3. macierz sąsiedztwa (matrix)
  int n,m;
  int u,v;
  const int maxn = 100;
  bool matrix[maxn][maxn];

  // matrix[0][3] = true / false
  // jezeli jest krawedz od 0 do 3, inaczej bedzie false
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    // graf nieskierowany
    matrix[u][v] = true;
    matrix[v][u] = true;
    // graf skierowany 
    matrix[u][v] = true;
  }


  // graf nieskierowany wazony
  n m 
  u1 v1 w1
  u2 v2 w2 
  u3 v3 w3
  ...
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  // const int maxn = 100;
  // vector<pair<int,int>> adj[maxn];
  int u,v,w;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }



}