#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> list(n, 0);
	for(auto &el : list) cin >> el;
	vector<int> res(n, 0);
	for(int i = 0; i < n; i++){
		res[list[i] - 1] = i+1;
	}
	for(auto el : res){
		cout << el << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 