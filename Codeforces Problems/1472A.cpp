#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int res = 1;
	while(!(a&1)){
		a /= 2;
		res*=2;
	}
	while(!(b&1)){
		b /= 2;
		res*=2;
	}
	if(res >= c){
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