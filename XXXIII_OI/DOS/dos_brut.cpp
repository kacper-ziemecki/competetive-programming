#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,q,x,y;
const int maxN = 1001;
string grid[maxN];
int dist[maxN][maxN];
bool vis[maxN][maxN];
int dirX[] = {1,0,-1,0}, dirY[] = {0,1,0,-1};

bool check(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == '#') return false;
	return true;
}

void bfs(){
	dist[0][0] = 0;
	vis[0][0] = true;
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		pair<int,int> u = q.front(); q.pop();
		int x = u.first, y = u.second;
		for(int i = 0; i < 4; i++){
			int x1 = x+dirX[i], y1 = y+dirY[i];
			if(check(x1,y1) && !vis[x1][y1]){
				vis[x1][y1] = true;
				dist[x1][y1] = dist[x][y]+1;
				q.push({x1,y1});
			}
		}
	}
}

void answer(){
	vector<int> forts;
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j] == 'F') forts.pb(dist[i][j]);
		}
	}
	sort(forts.begin(), forts.end(), greater<>());
	for(int i = 0; i < forts.size(); i++) res = max(res, i+forts[i]);
	cout << res << endl;
}
void solve(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> grid[i];
	bfs();
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++) cout << dist[i][j] << ' ';
	// 	cout << endl;
	// }
	answer();
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		x--; y--;
		if(grid[x][y] == 'F') grid[x][y] = '.';
		else grid[x][y] = 'F';
		answer();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}