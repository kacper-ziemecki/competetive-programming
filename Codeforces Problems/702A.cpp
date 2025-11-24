#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> lista(n, 0);
	for(auto &el : lista) cin >> el;
	ll res = 1;
	ll temp = 1;
	for(int i = 1; i < n; i++){
		if(lista[i] > lista[i-1]){
			temp++;
		}
		else{
			temp = 1;
		}
		res = max(res, temp);
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