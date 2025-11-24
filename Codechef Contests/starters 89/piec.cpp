#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	ll n;
	cin >> n;
	vector<ll> one(n, 0), two(n, 0);
	for(auto &el : one) cin >> el;
	for(auto &el : two) cin >> el;
	vector<bool> test(n-1, false);
	for(ll i = 1; i < n; i++){
		if(one[i] <= two[i-1]) test[i-1] = true;
	} 
	ll cnt = 0;
	ll res = 0;
	for(ll i = 0; i < n-1; i++){
		if(test[i] == true) cnt++;
		if(test[i] == false) cnt = 0;
		res = max(res, cnt);
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 