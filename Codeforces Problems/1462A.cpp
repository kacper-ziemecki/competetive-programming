#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> lista(n, 0),res(n, 0);
	for(auto &el : lista) cin >> el;
	ll i = 0, j = n-1;
	for(int x = 0; x < n; x++){
		if(x&1){
			res[x] = lista[j];
			j--;
		}
		else{
			res[x] = lista[i];
			i++;
		}
	}
	for(auto el : res) cout << el << " ";
	cout << endl;
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