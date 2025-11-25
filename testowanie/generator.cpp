#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int rnd(int a, int b){return rand()%(b-a+1) + a;}

vector<int> dirI = {-1,0,1,0}, dirJ = {0,1,0,-1};

bool canVisit(vector<string> &lista, vector<vector<bool>> &vis, int i, int j){
	int n = lista.size();
	if(i < 0 || j < 0 || i >= n || j >= n) return false;
	if(vis[i][j] || lista[i][j] == '#') return false;
	return true;
}

void dfs(int i, int j, vector<string> &lista, vector<vector<bool>> &vis){
	vis[i][j] = true;
	for(int k = 0; k < 4; k++){
		int i1 = i+dirI[k], j1 = j+dirJ[k];
		if(canVisit(lista,vis,i1,j1)) dfs(i1,j1,lista,vis);
	}
}

bool wszedzieDojscie(vector<string>& lista){
	int n = lista.size();
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	dfs(0,0, lista, vis);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(lista[i][j] != '#' && !vis[i][j]) return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int seed; 
	cin >> seed; 
	srand(seed);
	int n = rnd(2, 5), q = rnd(2, 5);
	vector<string> lista(n, string(n, '.'));
	int ilosc_scian = rnd(0, n*(n/2));
	lista[0][0] = 'Z';
	for(int k = 0; k < ilosc_scian; k++){
		int i = rnd(0, n-1), j = rnd(0, n-1);
		lista[i][j] = '#';
		while((i == 0 && j == 0) || !wszedzieDojscie(lista)){
			if(i == 0 && j == 0) lista[i][j] = 'Z';
			else lista[i][j] = '.';
			i = rnd(0, n-1);
			j = rnd(0, n-1);
		}
	}
	cout << n << ' ' << q << endl;
	for(auto sub : lista) cout << sub << endl;
	for(int k = 0; k < q; k++){
		int i = rnd(1, n), j = rnd(1, n);
		while(lista[i-1][j-1] != '.'){
			i = rnd(1, n); j = rnd(1, n);
		}
		cout << i << ' ' << j << endl;
	}
}
