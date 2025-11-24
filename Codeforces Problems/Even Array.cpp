#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	ll even = 0, odd = 0;
	ll temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(temp%2 == 0 && i%2 == 1) even++;
		if(temp%2 == 1 && i%2 == 0) odd++;
	}
	if(even != odd){
		cout << -1 << endl;
	}
	else{
		cout << even << endl;
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