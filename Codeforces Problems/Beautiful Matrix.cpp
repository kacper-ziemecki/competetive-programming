#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	vector<vector<int>> list(5, vector<int>(5, 0));
	for(auto &sub : list){
		for(auto &el : sub){
			cin >> el;
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(list[i][j] == 1){
				cout << abs(i - 2) + abs(j - 2) << endl;
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 