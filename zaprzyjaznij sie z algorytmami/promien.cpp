#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

bool test(vector<ll> trzy, ll index, ll r, ll liczba){
	ll temp = trzy[min(index + r, (long long)trzy.size() - 1)] - (index - r - 1 >= 0 ? trzy[index - r - 1] : 0);
	if(temp >= liczba) return true;
	return false;
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> jeden(n, 0), dwa(n, 0), trzy(n, 0);
	for(auto &el : jeden) cin >> el;
	for(auto &el : dwa) cin >> el;
	trzy[0] = jeden[0];
	for(int i = 1; i < n; i++){
		trzy[i] = trzy[i-1] + jeden[i];
	}
	for(int i = 0; i < n; i++){
		ll poczotek = 0, koniec = n - 1, srodek, wynik = -1;
		while(poczotek <= koniec){ 
			srodek = (poczotek + koniec) / 2;
			if(test(trzy, i, srodek, dwa[i])){
				koniec = srodek - 1;
				wynik = srodek;
			} 
			else{
				poczotek = srodek + 1;
			}
		}
		cout << wynik << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin); 
	solve();	
} 