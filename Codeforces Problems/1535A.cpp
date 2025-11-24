#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	vector<int> list(4, 0);
	for(auto &el : list) cin >> el;
	int maks1 = max(list[0], list[1]), maks2 = max(list[2], list[3]);
	sort(list.begin(), list.end());
	if((maks1 == list[3] && maks2 == list[2]) || (maks1 == list[2] && maks2 == list[3])){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
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