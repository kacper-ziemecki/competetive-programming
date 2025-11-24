#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(a-1 < abs(b-c) + c-1){
		cout << 1 << endl;
	}
	else if(a-1 > abs(b-c) + c-1){
		cout << 2 << endl;
	}
	else{
		cout << 3 << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 