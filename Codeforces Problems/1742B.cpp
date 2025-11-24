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
	for(int i = 1; i < n; i++){
		if(lista[i] == lista[i-1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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