#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> lista(n, 0);
	for(auto &el : lista) cin >> el;
	sort(lista.begin(), lista.end());
	ll res = 0;
	for(auto el : lista){
		res += el - lista[0];
	}
	cout << res << endl;
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