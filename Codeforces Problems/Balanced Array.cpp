#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	if(n%4 != 0){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int sum = 0;
	for(int i = 0; i < n/2; i++){
		cout << (i+1)*2 << " ";
		sum += (i+1)*2;
	}
	for(int i = 0; i < n/2 - 1; i++){
		cout << i*2 + 1 << " ";
		sum -= i*2 + 1;
	}
	cout << sum << endl;
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