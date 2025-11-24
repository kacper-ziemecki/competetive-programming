#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(abs(a-b) == 1 || 2 * abs(a-b) < c || 2 * abs(a-b) < a || 2 * abs(a-b) < b){
		cout << -1 << endl;
	}
	else{
		if(c + abs(a-b) > 2 * abs(a-b)){
			cout << c - abs(a-b) << endl;
			return;
		}
		cout << c + abs(a-b) << endl;
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