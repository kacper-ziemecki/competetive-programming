#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long




void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> lista(n, 0);
	for(auto &el : lista) cin >> el;
	sort(lista.begin(), lista.end());
	ll i = -1, j = n-k-1;
	ll suma = 0;
	for(int x = 0; x < n-k; x++) suma += lista[x];
	ll res = 0;
	for(int x = 1; x <= k; x++){
		res = max(res, suma);
		i += 2;
		j++;
		j = min(j, n);
		suma -= lista[i-1] + lista[i];
		if(j != n) suma += lista[j];
		res = max(res, suma);
	}
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