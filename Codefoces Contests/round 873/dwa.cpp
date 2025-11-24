#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	ll n;
	cin >> n;
	vector<ll> lista(n, 0);
	for(auto &el : lista) cin >> el;
	ll minimum = n+1;
	for(int i = 1; i <= n; i++){
		if(lista[i-1] != i){
			if(minimum == n+1){
				minimum = abs(lista[i-1] - i);
			}
			minimum = __gcd(minimum, abs(lista[i-1] - i));
		}
	}
	cout << minimum << endl;
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