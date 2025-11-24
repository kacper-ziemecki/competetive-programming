#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> lista(n, 0),res(n, 0);
	for(auto &el : lista) cin >> el;
	sort(lista.begin(), lista.end());
	int jeden=0, dwa=n/2;
	for(int i = 0; i < n; i++){
		if(i&1){
			res[i] = lista[jeden++];
		}
		else{
			res[i] = lista[dwa++];
		}
	}
	ll wynik = 0;
	for(int i = 1; i < n-1; i++){
		if(res[i] < res[i-1] && res[i] < res[i+1]) wynik++;
	}
	cout << wynik << endl;
	for(auto el : res) cout << el << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin); 
	solve();	
} 