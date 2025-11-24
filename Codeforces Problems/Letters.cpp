#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,m,a;
	cin >> n >> m;
	vector<int> lista(n, 0);
	for(int i = 0; i < n; i++){
		cin >> a;
		if(i == 0){
			lista[i] = a;
		}
		else{
			lista[i] = lista[i-1] + a;
		}
	}
	for(auto el : lista) cout << el << " ";
	for(int i = 0; i < m; i++){
		cin >> a;
		int poczotek = 0, koniec = n-1, srodek, wynik = -1;
		while(poczotek <= koniec){ 
			srodek = (poczotek + koniec) / 2;
			if(lista[srodek] <= a){
				poczotek = srodek+1;
				wynik = srodek;
			} 
			else{
				koniec = srodek-1;
			}
		}
		cout << wynik << " " << a << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin); 
	solve();	
} 