#include<bits/stdc++.h>
using namespace std;
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,m;

//--------------BRUT-----------
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

int min_size(){
	for(int length = 1; length < min(n,m)+1; length++){
		st.clear();
		helper(length);
		for(auto permutation : st){
			if(checking(permutation)){
				return permutation.size();
			}
		}
	}
}
//-----------------KONIEC BRUT-----------------

string wzor(){
	// cout << "WZOR: ";
	// dbg(n,m);
	if(__gcd(n,m) == 1){
		return "DL"; 
	} else {
		int GCD = __gcd(n,m);
		if(GCD % 4 == 0){
			if(n < m){
				return string(GCD-1, 'L') + 'D';
			} else{
				return 'L' + string(GCD-1, 'D');
			}
		} else if(GCD % 2 == 0){
			if(n < m){
				return string(GCD-1, 'D') + 'L';
			} else{
				return 'L' + string(GCD-1, 'D');
			}
		}
		// string res(GCD, 'D');
		// for(int i = GCD-1; i >= 0; i--){
		// 	res[i] = 'L';
		// 	if(checking(res)) return res;
		// }

		if(n > m){
			return string(GCD-1, 'D') + 'L';
		} else{
			return 'L' + string(GCD-1, 'D');
		}
	}
	
}

void solve(){
	for(n = 2; n < 20; n++){
		for(m = 2;m < 20; m++){
			if(__gcd(n,m) > 7 || __gcd(n,m)&1){
				cout << "POMIJAMY: ";
				dbg(n,m);
				continue;
			}
			// dbg(n,m);
			string wzorzec = wzor();
			int correct_length = min_size();
			if(wzorzec.size() != correct_length){
				cout << "NOT CORRECT LENGTH: ";
				dbg(wzorzec,correct_length, n,m);
			} else if(!checking(wzorzec)){
				cout << "DOES NOT COVER WHOLE: ";
				dbg(wzorzec,correct_length, n,m);
			}
		}
	}
} 

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	freopen("../../test.out", "w", stdout);
	solve();
}