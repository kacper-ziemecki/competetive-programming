#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	ll n;
	cin >> n;
	vector<ll> lista(n, 0);
	ll suma = 0;
	for(ll i = 1; i <= n; i++){
		lista[i-1] = i;
		suma += i;
	}
	lista[0] += suma%n;
	for(auto el : lista){
		cout << el << " ";
	}
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