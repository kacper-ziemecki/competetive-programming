#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	ll n;
	cin >> n;
	vector<ll> lista = {};
	ll temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(i == 0){
			lista.push_back(temp);
		}
		else if(lista[lista.size() - 1] != temp) lista.push_back(temp);
	}
	if(lista.size() == 1){
		cout << 1 << endl;
		return;
	}
	ll res = 0; 
	// for(auto el : lista) cout << el << " ";
	// cout << endl;
	for(ll i = 1; i < lista.size()-1; i++){
		if(lista[i] < lista[i-1] && lista[i] < lista[i+1]) res++;
		if(lista[i] > lista[i-1] && lista[i] > lista[i+1]) res++;
	}
	if(lista.size() >= 2) res += 2;
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