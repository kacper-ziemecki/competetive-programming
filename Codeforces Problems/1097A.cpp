#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	vector<string> list(6, " ");
	for(auto &el : list) cin >> el;
	for(int i = 1; i < 6; i++){
		if(list[i][0] == list[0][0]){
			cout << "YES\n";
			return;
		}
		if(list[i][1] == list[0][1]){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 