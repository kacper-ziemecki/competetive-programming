#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,res=0;
	cin >> n;
	vector<pair<int, int>> list(n, {0, 0});
	for(auto &el : list) cin >> el.first >> el.second;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j && list[i].first == list[j].second) res++;
		}
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