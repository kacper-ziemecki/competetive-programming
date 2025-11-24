#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void bfs(vector<vector<int>> lista, int n, int s){
	queue<int> q;
	vector<bool> vis(n);
	vector<int> d(n), p(n)
	q.push(s);
	vis[s] = true;
	p[s] = -1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int u : lista[v]){
			if(!vis[u]){
				vis[u] = true;
				q.push();
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}
}

void solve(){
	int n,a,b;
	cin >> n >> m;
	vector<vector<int>> lista;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		lista[a].push_back(b);
	}
	bfs(lista, n, a);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 
