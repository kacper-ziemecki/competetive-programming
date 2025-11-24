#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long long int n,m,cnt=0,a;
	cin >> n >> m;
	vector<bool> lista(n+1, false);
	for(long long int i = 0; i < m; i++){
		cin >> a;
		if(!lista[a]){
			cnt++;
			lista[a] = true;
		}
		if(cnt == n){
			cout << i + 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	
} 