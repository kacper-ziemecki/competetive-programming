#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long long int n,m,maks=0,a,temp=0;
	cin >> n >> m;
	vector<long long int> lista(n+1, 0);
	for(int i = 0; i < m; i++){
		cin >> a;
		if(a == n+1){
			maks = temp;
		}
		else{
			lista[a] = max(maks, lista[a]) + 1;
			temp = max(temp, lista[a]);
		}
	}
	for(int i = 1; i < n+1; i++){
		cout << max(maks, lista[i]) << " ";
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