#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long long unsigned int n,res=0;
	cin >> n;
	vector<int> lista(n, 0);
	vector<long long unsigned int> suffix(n, 0);
	for(auto &el : lista) cin >> el;
	for(long long int i = n-1; i >= 0; i--){ 
		suffix[i] = (i == n-1 ? 0 : suffix[i+1]) + (lista[i] == 1 ? 1 : 0);
		if(lista[i] == 0) res+= suffix[i];
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