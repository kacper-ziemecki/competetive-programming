#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int maks = INT_MIN;
	vector<int> list(n, 0);
	for(auto &el : list){
		cin >> el;
		maks = max(maks, el);
	}
	int res = 0;
	for(auto el : list){
		res += maks - el;
	}
	cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 