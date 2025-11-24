#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> one(n, 0), two(n, 0);
	for(auto &el :  one) cin >> el;
	for(auto &el : two) cin >> el;
	int first = INT_MAX, second = INT_MAX;
	for(int i = 0; i < n; i++){
		first = min(first, one[i]);
		second = min(second, two[i]);
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		int combined = min(one[i] - first, two[i] - second);
		res += combined;
		res += one[i] - first - combined;
		res += two[i] - second - combined;
	}
	cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 