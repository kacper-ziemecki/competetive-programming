#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	if(n == 2 || n == 3){
		cout << 1 << endl;
		cout << n << endl;
	}
	else if(n&1){
		cout << (n-3)/2 + 1 << endl;
		cout << 3 << " ";
		for(int i = 0; i < (n-3)/2; i++){
			cout << 2 << " ";
		}
		cout << endl;
	}
	else{
		cout << n/2 << endl;
		for(int i = 0; i < n/2; i++){
			cout << 2 << " ";
		}
		cout << endl;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 