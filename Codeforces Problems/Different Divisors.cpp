#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

ll test(ll liczba){
	vector<ll> v;
	ll res = INT_MAX;
	for(int i = 1; i * i <= liczba; i++){
		if(liczba % i == 0){
			v.push_back(i); 
			v.push_back(liczba / i);
		}
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < v.size(); i++){
		res = min(res, v[i] - v[i-1]);
	}
	return res;
}

void solve(){
	ll d;
	cin >> d;
	ll poczotek = 6, koniec = 20, wynik = -1;
	while(poczotek <= koniec){
		ll srodek = (poczotek + koniec) / 2;
		cout << poczotek << " " << srodek << " " << koniec << endl;
		if(test(srodek) <= d){
			poczotek = srodek;
			wynik = srodek;
		} 
		else{
			koniec = srodek - 1;
		}
	}
	cout << wynik << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin); 
	int t;
	cin >> t;
	while(t--)
	solve();	
} 