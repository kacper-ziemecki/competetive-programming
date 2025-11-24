#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	if(n == 3){
		cout << "NO\n";
	}
	else if((n-4) % 4 != 0){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
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