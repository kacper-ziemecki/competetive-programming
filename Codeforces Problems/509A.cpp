#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<vector<ll>> lista(n, vector<ll>(n, 1));
	for(ll i = 1; i < n; i++){
		for(ll j = 1; j < n; j++){
			lista[i][j] = lista[i-1][j] + lista[i][j-1];
		}
	}
	cout << lista[n-1][n-1] << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 