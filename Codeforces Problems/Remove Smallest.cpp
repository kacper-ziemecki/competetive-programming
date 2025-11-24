#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> list(n, 0);
	for(auto &el : list) cin >> el;
	sort(list.begin(), list.end());
	for(int i = 1; i < n; i++){
		if(abs(list[i] - list[i-1]) > 1){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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