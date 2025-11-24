#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	ll odd = 0, even = 0, temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(temp&1) odd += temp;
		else even += temp;
	}
	if(odd >= even) cout << "NO\n";
	else cout << "YES\n";
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