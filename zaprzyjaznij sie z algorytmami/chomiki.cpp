#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,m,a,b;
	cin >> n >> m;
	vector<int> lista(n,0);
	for(auto &el : lista) cin >> el;
	vector<int> jeden(n,0), dwa(n, 0), trzy(n, 0), cztery(n, 0), piec(n, 0);
	for(int i = 0; i < n; i++){
		jeden[i] = (i == 0 ? 0 : jeden[i-1]) + (lista[i] == 1 ? 1 : 0);
		dwa[i] = (i == 0 ? 0 : dwa[i-1]) + (lista[i] == 2 ? 1 : 0);
		trzy[i] = (i == 0 ? 0 : trzy[i-1]) + (lista[i] == 3 ? 1 : 0);
		cztery[i] = (i == 0 ? 0 : cztery[i-1]) + (lista[i] == 4 ? 1 : 0);
		piec[i] = (i == 0 ? 0 : piec[i-1]) + (lista[i] == 5 ? 1 : 0);
	}
	for(int i = 0 ; i < m; i++){
		cin >> a >> b;
		if(jeden[b - 1] - (a == 1 ? 0 :jeden[a - 2]) > 0){
			cout << 1 << endl;
		}
		else if(dwa[b - 1] - (a == 1 ? 0 :dwa[a - 2]) > 0){
			cout << 2 << endl;
		}
		else if(trzy[b - 1] - (a == 1 ? 0 :trzy[a - 2]) > 0){
			cout << 3 << endl;
		}
		else if(cztery[b - 1] - (a == 1 ? 0 :cztery[a - 2]) > 0){
			cout << 4 << endl;
		}
		else if(piec[b - 1] - (a == 1 ? 0 :piec[a - 2]) > 0){
			cout << 5 << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	
} 