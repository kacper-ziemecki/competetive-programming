#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long



void solve(){
	vector<int> lista(4, 0);
	for(auto &el : lista) cin >> el;
	int jeden = max(lista[0], lista[1]);
	int dwa = max(lista[2], lista[3]);
	sort(lista.begin(), lista.end());
	if((jeden == lista[3] && dwa == lista[2]) || (jeden == lista[2] && dwa == lista[3])){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	
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
