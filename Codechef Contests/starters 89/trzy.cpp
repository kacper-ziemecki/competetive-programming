#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	ll minimum = n-1, maks = 0,wielkosc = 0, res=0;
	unordered_map<ll, ll> lista;
	for(ll i = 0; i < n; i++){
		lista[list[i]] = i;
	}
	sort(list.rbegin(), list.rend());
	for(auto el : list){
		wielkosc++;
		minimum = min(minimum, lista[el]);
		maks = max(maks, lista[el]);
		if(maks - minimum + 1 == wielkosc && wielkosc != n){
			res = max(res, wielkosc);
		}
	}
	cout << res << endl;
	
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