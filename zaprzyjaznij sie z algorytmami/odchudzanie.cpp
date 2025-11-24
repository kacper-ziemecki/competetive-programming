#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> lista(n, 0);
	for(auto &el : lista) cin >> el;
	vector<int> jeden(n, 0);
	jeden[0] = lista[0];
	for(int i = 1; i < n; i++){
		jeden[i] = max(lista[i], jeden[i-1]);
	}
	int minimum = lista[n-1];
	int res = 0;
	for(int i = n-2; i > 0; i--){
		minimum = min(minimum, lista[i]);
		res = max(res, jeden[i-1] - minimum);
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 
