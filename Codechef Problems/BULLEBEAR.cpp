#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	if(a == b){
		cout << "NEAUTRAL\n"; 
	}
	else if(a < b){
		cout << "PROFIT\n";
	}
	else {
		cout << "LOSS\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
