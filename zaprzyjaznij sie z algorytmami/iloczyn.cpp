#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> lista(n, 0);
	for(auto &el : lista) cin >> el;
	sort(lista.begin(), lista.end());
	cout << max(lista[0] * lista[1] * lista[n-1], lista[n-1] * lista[n-2] * lista[n-3]) << endl;
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