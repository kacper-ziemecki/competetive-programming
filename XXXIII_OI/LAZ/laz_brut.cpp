#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,m;
bool flag;
set<string> st;
set<string> res;
void helper(int length, string s=""){
	if(length == 0){
		st.emplace(s); 
		return;
	}
	helper(length-1, s+'G');
	helper(length-1, s+'D');
	helper(length-1, s+'P');
	helper(length-1, s+'L');
}

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
void solve(){
	cin >> n >> m;
	for(int length = 1; length < min(n,m)+1; length++){
		st.clear();
		helper(length);
		flag = false;
		for(auto permutation : st){
			if(checking(permutation)){
				res.emplace(permutation);
				flag = true;
			}
		}
		if(flag) break;
	}
	for(auto permutation : res) cout << permutation << endl;
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("../../in.in", "r", stdin);
	freopen("../../out.out", "w", stdout);

	solve();
}