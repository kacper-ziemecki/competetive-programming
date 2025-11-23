#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

int n,m,u,v;
const int maxN = 1e6;
vector<int> adj[maxN];
bool vis[maxN];

void dfs(int u){
	vis[u] = true;
	for(auto v : adj[u]){
		if(!vis[v]) dfs(v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]) dfs(i);		
	}
	cout << endl << '\n';
}	
