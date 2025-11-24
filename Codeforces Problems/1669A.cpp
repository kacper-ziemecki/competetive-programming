#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	sort(list.begin(), list.end());
	for(int i = 2; i < n; i++){
		if(list[i] == list[i-1] && list[i-1] == list[i-2]){
			cout << list[i] << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 