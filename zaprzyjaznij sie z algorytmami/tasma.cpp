#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long long int n, prawo=0, lewo=0, res = INT_MAX;
	cin >> n;
	vector<long long int> lista(n, 0);
	for(long long int &el : lista){
		cin >> el;
		prawo+= el;
	}
	for(int i = 0; i < n - 1; i++){
		prawo -= lista[i];
		lewo += lista[i];
		res = min(res, abs(prawo - lewo));
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