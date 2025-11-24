#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long long int n, a;
	cin >> n;
	vector<bool> lista(n+1, false);
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a > n || lista[a]){
			cout << "NIE\n";
			return;
		}
		lista[a] = true;
	}
	cout << "TAK\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	
} 