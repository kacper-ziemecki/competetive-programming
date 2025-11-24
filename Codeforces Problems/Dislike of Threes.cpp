#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(vector<int>& lista){
	int k;
	cin >> k;
	cout << lista[k-1] << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	vector<int> lista;
	for(int i = 1; i < 10001; i++){
		if(!((i%3 == 0) || (i%10 == 3))) lista.push_back(i);
	}
	int t;
	cin >> t;
	while(t--) solve(lista);	
} 