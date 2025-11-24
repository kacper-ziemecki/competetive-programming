#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,m;
	cin >> n >> m;
	pair<int, int> temp = {1, n-1}, res = {1, n-1};
	vector<int> lista(n, 0);
	for(auto &el : lista) cin >> el;
	sort(lista.begin(), lista.end());
	for(int i = 1; i < n; i++){
		if(lista[i] == lista[i-1]){
			temp.first++;
			temp.second = n - i - 1;
		}
		else{
			temp.first = 1;
			temp.second = n - i - 1;
		}
		if(res.first+min(res.second,m) < temp.first+min(temp.second,m)){
			res.first = temp.first;
			res.second = temp.second;
		}
	}
	cout << min(res.first + m, res.first + res.second) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	
} 