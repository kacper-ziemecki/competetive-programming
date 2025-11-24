#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(a < b && b == c){
		cout << "YES\n";
		cout << a << " " << a << " " << c << endl;
	}
	else if(a == b && b == c){
		cout << "YES\n";
		cout << a << " " << b << " " << c << endl;
	}
	else if(a > b && b < c){
		cout << "YES\n";
		cout << a << " " << b << " 1\n";
	}
	else{
		cout << "NO\n";
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