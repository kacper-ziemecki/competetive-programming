#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int wyszukiwanie_binarne(vector<int> lista, int liczba){
	int poczotek = 0, koniec = lista.size()-1, wynik = -1;
	while(poczotek <= koniec){
		int srodek = (poczotek + koniec) / 2;
		if(lista[srodek] <= liczba){
			poczotek = srodek+1;
			wynik = srodek;
		}
		else {
			koniec = srodek - 1;
		}
	}
	return wynik;
}

void solve(){
	vector<int> lista = {1,2,3,4,5,6,7,9,12};

	cout << wyszukiwanie_binarne(lista, 4);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("input.txt", "r", stdin);
	solve();	
} 