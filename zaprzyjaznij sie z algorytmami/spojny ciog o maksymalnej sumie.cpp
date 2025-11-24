#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int suma1(vector<int> lista){
	vector<int> wynik(lista.size(), 0);
	wynik[0] = lista[0];
	int res = INT_MIN;
	for(int i = 1; i < lista.size(); i++){
		wynik[i] = max(wynik[i-1] + lista[i], lista[i]);
		res = max(res, wynik[i]);
	}	
	return res;
}

int suma2(vector<int> lista){
	int temp = lista[0],res = lista[0];
	for(int i = 1; i < lista.size(); i++){
		temp = max(temp + lista[i], lista[i]);
		res = max(res, temp);
	}
	return res;
}
void solve(){
	int n;
	cin >> n;
	vector<int> lista(n, 0);
	for(auto &el : lista) cin >> el;

	cout << suma1(lista) << endl;
	cout << suma2(lista) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	solve();	
} 