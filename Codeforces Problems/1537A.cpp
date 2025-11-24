#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(){
	ld n;
	cin >> n;
	ld suma = 0;
	vector<ld> lista(n, 0);
	for(auto &el : lista){
		cin >> el;
		suma += el;
	}
	if(suma / n == 1){
		cout << 0 << endl;
	}
	else if(suma / n < n){
		cout << 1 << endl;
	}
	else{
		cout << suma - n << endl;
	}
}  

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 