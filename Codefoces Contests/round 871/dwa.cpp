#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> list(n, 0);
	for(auto &el : list) cin >> el;
	int res=0, temp=0;	
	if(list[0] == 0) temp = 1;
	for(int i = 1; i < n; i++){
		res = max(res, temp);
		if(list[i] == 0){
			temp++;
		}
		else{
			temp = 0;
		}
	}
	res = max(res, temp);
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