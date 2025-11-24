#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int n,a,b;
vector<bool> vis(n);
vector<vector<int>> lista;

void dfs(int v){
	vis[v] = true;
	for(int u : lista[v]){
		if(!vis[u]) dfs(u);
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		lista[a].push_back(b);
	}
	dfs(a);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 
