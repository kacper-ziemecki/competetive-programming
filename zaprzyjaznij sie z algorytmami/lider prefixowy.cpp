#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,a;
	pair<int,int> lider = {INT_MIN, INT_MIN};
	pair<int,int> wynik = {INT_MIN, INT_MIN};
	cin >> n;
	unordered_map<int,int> mapa, lidery;
	for(int i = 0; i < n; i++){
		cin >> a;
		mapa[a]++;
		if(lider.first < mapa[a]){
			lider.first = mapa[a];
			lider.second = a;
		}
		if(lider.first * 2 > i+1){
			lidery[lider.second]++;
			if(lidery[lider.second] > wynik.first){
				wynik.first = lidery[lider.second];
				wynik.second = lider.second;
			}
		}
	}
	if(wynik.first * 2 <= n){
		cout << "NIE\n";
	}
	else cout << wynik.second << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 