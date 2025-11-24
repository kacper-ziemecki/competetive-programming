#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b;
	cin >> a >> b;
	ll temp = a;
	if(b == a){
		cout << "YES\n";
		return;
	}
	while(a % 2 == 0){
		a /= 2;
	}
	if(b % a == 0 && b <= temp){
		cout << "YES\n";
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
	int t;
	cin >> t;
	while(t--) solve();	
} 