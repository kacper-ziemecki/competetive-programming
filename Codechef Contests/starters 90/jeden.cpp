#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	for(auto &el : list){
		if(el == 1) el = 0;
		else el = 1;
	}
	for(auto el : list) cout << el << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 