#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,q,x,y;
const int maxN = 1001, INF=1e6;
string grid[maxN];
int dist[maxN][maxN];
bool vis[maxN][maxN];
int dirX[] = {1,0,-1,0}, dirY[] = {0,1,0,-1};

int convert[maxN][maxN];
set<vector<int>> ordered;

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

void calc_convert(){
	vector<vector<int>> distances; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j] != '#' && grid[i][j] != 'Z') distances.pb(vector<int>{dist[i][j], i, j});
		}
	}
	sort(distances.begin(), distances.end(), greater<>()); // {100, 89, 72, 53, 50, 13} -> malejąco dystanse trzeba posortowac inaczej
	int i = 0;
	for(auto el : distances){
		convert[el[1]][el[2]] = i;
		i++;
	}
}

void calc_order(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j] == 'F') ordered.emplace(vector<int>{convert[i][j], i, j});
		}
	}
}

class SegTree{
public:
	vector<int> mx,prop,suma;
	int length;
	SegTree(int n){
		length = 1;
		while(length < n) length <<= 1;
		mx.assign(2*length, 0);
		prop.assign(2*length, 0);
		suma.assign(2*length, 0);
	}

	void propagate(int x){
		if(x >= 2*length) return; // w razie co, jezeli sie jest poza lista
		if(mx[x]) mx[x] += prop[x]; // jezeli cos jest na tym index w ogole
		if(x*2+1 < 2*length) prop[2*x+1] += prop[x];
		if(x*2+2 < 2*length) prop[2*x+2] += prop[x];
		prop[x] = 0;
	}

	void create(int i, int v, int x, int lx, int rx){
		propagate(x);
		if(rx == lx){
			mx[x] = v;
			suma[x] = 1;
			return;
		}

		int mid = (lx+rx)/2;
		if(i <= mid) create(i,v,x*2+1,lx,mid);
		else create(i,v,x*2+2,mid+1,rx);

		mx[x] = max(mx[x*2+1], mx[x*2+2]);
		suma[x] = suma[x*2+1]+suma[x*2+2];
	}
	void create(int i, int v){
		create(i,v,0,0,length-1);
	}

	void _delete(int i, int x, int lx, int rx){
		propagate(x);
		if(rx == lx){
			mx[x] = 0;
			suma[x] = 0;
			return;
		}

		int mid = (lx+rx)/2;
		if(i <= mid) _delete(i,x*2+1,lx,mid);
		else _delete(i,x*2+2,mid+1,rx);

		mx[x] = max(mx[x*2+1], mx[x*2+2]);
		suma[x] = suma[x*2+1]+suma[x*2+2];
	}
	void _delete(int i){
		_delete(i,0,0,length-1);
	}
	void add(int l, int x, int lx, int rx){
		propagate(x);
		if(rx < l) return;
		if(lx >= l){
			prop[x]++;
			propagate(x);
			return;
		}
		int mid = (lx+rx)/2;
		add(l,x*2+1,lx,mid);
		add(l,x*2+2,mid+1,rx);
		mx[x] = max(mx[2*x+1], mx[2*x+2]);
	}
	void add(int l){ // l...n*n-1 dodac albo odjoc jeden
		add(l,0,0,length-1);
	}
	void subtract(int l, int x, int lx, int rx){
		propagate(x);
		if(rx < l) return;
		if(lx >= l){
			prop[x]--;
			propagate(x);
			return;
		}
		int mid = (lx+rx)/2;
		subtract(l,x*2+1,lx,mid);
		subtract(l,x*2+2,mid+1,rx);
		mx[x] = max(mx[2*x+1], mx[2*x+2]);
	}
	void subtract(int l){ // l...n*n-1 dodac albo odjoc jeden
		subtract(l,0,0,length-1);
	}
	int sum(int l, int r, int x, int lx, int rx){
		if(l <= lx && rx <= r) return suma[x];
		if(rx < l || r < lx) return 0;

		int mid = (lx+rx)/2;
		int left = sum(l,r,x*2+1,lx,mid);
		int right = sum(l,r,x*2+2,mid+1,rx);
		return left + right;
	}

	int sum(int l, int r){
		return sum(l,r,0,0,length-1);
	}
	int getMax(){
		return mx[0];
	}
};

void print_mx(SegTree segtree) {
	cout << "MX:\n";
    for(int i = 0; i < 2*segtree.length-1; i++){
        cout << segtree.mx[i] << ' ';
        if(__builtin_popcount(i+2) == 1) {
            cout << "\n";
        }

    }
    cout << "\n";
}
void print_sum(SegTree segtree){
	cout << "SUM:\n";
    for(int i = 0; i < 2*segtree.length-1; i++){
        cout << segtree.suma[i] << ' ';
        if(__builtin_popcount(i+2) == 1) {
            cout << "\n";
        }

    }
    cout << "\n";
}
void print_prop(SegTree segtree){
	cout << "PROP:\n";
    for(int i = 0; i < 2*segtree.length-1; i++){
        cout << segtree.prop[i] << ' ';
        if(__builtin_popcount(i+2) == 1) {
            cout << "\n";
        }

    }
    cout << "\n";
}

void print_dist(){
	cout << "DIST: \n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void print_convert(){
	cout << "CONVERT: \n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << convert[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void solve(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> grid[i];

	SegTree segtree(n*n+1);
	bfs();
	calc_convert();
	calc_order();

	// najpierw wpychamy do drzewa przedzialowego wszystkie forty
	for(auto el : ordered){
		int x = el[1], y = el[2];
		// dbg(convert[x][y]);
		// dbg(segtree.sum(0,convert[x][y]-1),x,y);
		// dbg(dist[x][y], dist[x][y]+segtree.sum(0,convert[x][y]-1));
		segtree.create(convert[x][y], dist[x][y]+segtree.sum(0,convert[x][y]-1));
		// print_sum(segtree); print_mx(segtree); print_prop(segtree);
	}
	print_dist();
	print_convert();
	cout << segtree.getMax() << endl;
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		x--; y--;
		dbg(x,y,convert[x][y]);
		if(grid[x][y] == 'F'){
			grid[x][y] = '.';
			segtree._delete(convert[x][y]);
			segtree.subtract(convert[x][y]+1);
		}
		else{
			grid[x][y] = 'F';
			segtree.create(convert[x][y], dist[x][y]+segtree.sum(0,convert[x][y]-1));
			segtree.add(convert[x][y]+1);
		}

		cout << segtree.getMax() << endl;
		print_sum(segtree); print_mx(segtree); print_prop(segtree);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}

// Z...
// ###.
// F.#F
// ...F