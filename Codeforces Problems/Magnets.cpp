#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int res = 1;
	vector<string> list(n, " ");
	for(auto &el : list) cin >> el;
	for(int i = 1; i < n; i++){
		if(list[i] != list[i-1]) res++;
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