#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	bool odd = false, even = false;
	ll temp;
	ll suma = 0;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(temp&1) odd = true;
		else even = true;
		suma += temp;
		suma %= 2;
	}
	if(suma == 1){
		cout << "YES\n";
	}
	else if(even && odd){
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
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 