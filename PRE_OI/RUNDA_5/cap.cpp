#include <bits/stdc++.h>

#include "caplib.h"

using namespace std;

void delete_leafs(set<pair<int,int>> &edges, int n){
    vector<int> deg(n+1);
    vector<pair<int,int>> to_erase;
    for(auto edge : edges){
        deg[edge.first]++;
        deg[edge.second]++;
    } 
    for(auto el : edges){
        if((deg[el.first] == 1 && el.first != 1) || (deg[el.second] == 1 && el.second != 1)){
            to_erase.push_back(el);
        }
    }
    for(auto el : to_erase) edges.erase(el);
}

int dfs(int u, int p, vector<vector<int>>& adj, vector<int>& depth){
    depth[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            depth[u] = max(depth[u], 1+dfs(v,u,adj,depth));
        }
    }
    return depth[u];
}

vector<int> calculate_depth(set<pair<int,int>> &edges, int n){
    vector<vector<int>> adj(n);
    vector<int> depth(n);
    for(auto el : edges){
        adj[el.first].push_back(el.second);
        adj[el.second].push_back(el.first);
    }
    dfs(1, 1, adj, depth);
    return depth;
}

vector<int> oblicz_rozgalezienia(set<pair<int,int>> &edges, int n){
    vector<int> deg(n+1);
    vector<int> rozgalezienia = {1};
    for(auto edge : edges){
        deg[edge.first]++;
        deg[edge.second]++;
    } 
    for(int u = 2; u <= n; u++){
        if(deg[u] > 2) rozgalezienia.push_back(u);
    }
    return rozgalezienia;
}

void dfs_leafs(int u, int p, vector<vector<int>>& adj, vector<int>& leafs){
    if(adj[u].size() == 0 || (adj[u].size() == 1 && adj[u][0] == p)){
        leafs.push_back(u);
        return;
    }
    for(auto v : adj[u]){
        if(v != p) dfs_leafs(v,u,adj,leafs);
    }
}

vector<int> oblicz_leafs(int u, set<pair<int,int>>& edges, int n){
    vector<int> leafs;
    vector<vector<int>> adj(n);
    for(auto el : edges){
        adj[el.first].push_back(el.second);
        adj[el.second].push_back(el.first);
    }
    dfs_leafs(u,u,adj,leafs);
}
void calc_dist(int u, int p, vector<vector<int>>& adj, vector<int>& dist){
    dist[u] = dist[p]+1;
    for(auto v : adj[u]) if(v != p) calc_dist(v,u,adj,dist);
}
void calc_parent(int u, int p, vector<vector<int>>& adj, vector<int>& parent){
    parent[u] = p;
    for(auto v : adj[u]) if(v != p) calc_dist(v,u,adj,dist);
}

int calc_mid(int lewo, int prawo, vector<int>& dist, vector<int>& parent){
    int distance = dist[prawo]-dist[lewo];
    int res = prawo;
    for(int i = 0; i < (distance+1)/2; i++) res = parent[res];
    return res;
}

int znajdz_capka(int n, std::vector<std::pair<int, int>> galezie) {
    set<pair<int,int>> edges;
    int operacje = 0;
    int ostatni_wezel = 1;
    for(auto el : galezie) edges.emplace(el);

    vector<vector<int>> adj(n);
    for(auto el : edges){
        adj[el.first].push_back(el.second);
        adj[el.second].push_back(el.first);
    }
    vector<int> dist(n,0);
    calc_dist(1,1,adj,dist);
    vector<int> parent(n,0);
    calc_parent(1,1,adj,parent);
    vector<int> deg(n+1);
    for(auto edge : galezie){
        deg[edge.first]++;
        deg[edge.second]++;
    }
    int leaf=1;
    for(int u = 2; u <= n; u++){
        if(deg[u]==1){
            leaf=u;
            break;
        }
    }
    for(int i = 0; i < 100; i++){
        if(zapytaj(leaf)) return leaf;
        delete_leafs(edges,n);
    }
    vector<int> rozgalezienia = oblicz_rozgalezienia(edges,n);
    vector<int> depth = calculate_depth(edges, n);
    vector<pair<int,int>> wierzcholki;
    for(auto roz : rozgalezienia){
        wierzcholki.push_back(make_pair(depth[roz], roz));
    }
    sort(wierzcholki.begin(), wierzcholki.end(), greater<>());
    for(auto wierzcholek : wierzcholki){
        int d = wierzcholek.first;
        int r = wierzcholek.second;
        if(zapytaj(r)){
            vector<int> leafs = oblicz_leafs(r, edges, n);
            for(auto leaf : leafs){
                //wyszukiwanie binarne od r do leaf
                int lewo = r, prawo = leaf;
                while(dist[lewo] < dist[prawo]){
                    int mid = calc_mid(lewo,prawo); // blizej do lewo
                    if(zapytaj(mid)){
                        lewo = mid;
                    } else{
                        prawo = parent[parent[mid]];
                        lewo = parent[lewo];
                    }
                }
            }
        } 
    }
    return 1;
}
