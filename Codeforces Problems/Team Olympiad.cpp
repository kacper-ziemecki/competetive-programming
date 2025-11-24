#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int temp;
	vector<int> one,two,three;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == 1) one.push_back(i+1);
		if(temp == 2) two.push_back(i+1);
		if(temp == 3) three.push_back(i+1);
	}
	int res = min(one.size(), min(two.size(), three.size()));
	cout << res << endl;
	for(int i = 0; i < res; i++){
		cout << one[i] << " " << two[i] << " " << three[i] << endl;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 