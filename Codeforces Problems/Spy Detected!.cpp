#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> list(n, 0);
	for(auto &el : list) cin >> el;
	for(int i = 0; i < n-2; i++){
		if(list[i]!= list[i+1] && list[i] != list[i+2]){
			cout << i+1 << endl;
			return;
		}
	}
	if(list[n-2] != list[n-1] && list[n-2] != list[n-3]){
		cout << n-1 << endl;
	}
	else{
		cout << n << endl;
	}
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