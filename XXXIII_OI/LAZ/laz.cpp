#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,m;

bool checking(string s){
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<vector<bool>> begining(n, vector<bool>(m, false));
	int cnt = 0, i = 0, x=0,y=0;
	// dbg(s);
	while(cnt < m*n){
		// dbg(x,y);
		if(i == 0 && begining[x][y]) return false;
		if(i == 0) begining[x][y] = true; 
		if(!vis[x][y]) cnt++;
		vis[x][y] = true;

		if(s[i] == 'G'){
			x--;
		} else if(s[i] == 'D'){
			x++;
		} else if(s[i] == 'P'){
			y++;
		} else{
			y--;
		}
		x = (x % n + n) % n;
		y = (y % m + m) % m;
		i = (i+1) % s.size();
	} 
	return true;
}
string wzor(){
	if(__gcd(n,m) == 1){
		return "DL"; 
	} else {
		int GCD = __gcd(n,m);
		string res1(GCD, 'D');
		for(int i = GCD-1; i > 0; i--){
			res1[i] = 'L';
			if(checking(res1)) return res1;
		}
		string res2(GCD, 'L');
		for(int i = GCD-1; i > 0; i--){
			res2[i] = 'D';
			if(checking(res2)) return res2;
		}
	}
}
void solve(){
	cin >> n >> m;
	string res = wzor();
	cout << res.size() << endl;
	cout << res << endl;
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}