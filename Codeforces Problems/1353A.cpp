#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b;
	cin >> a >> b;
	if(a >= 3){
		cout << 2*b << endl;
	}
	else if(a == 2){
		cout << b << endl;
	}
	else{
		cout << 0 << endl;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 