#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	vector<int> list(4, 0);
	for(auto &el : list) cin >> el;
	sort(list.begin(), list.end());
	int res = 1;
	for(int i = 1; i < 4; i++){
		if(list[i] != list[i-1]) res++;
	}
	cout << 4-res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 