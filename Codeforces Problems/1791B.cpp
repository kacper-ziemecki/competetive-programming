#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	string text;
	cin >> text;
	int x = 0, y = 0;
	for(auto el : text){
		if(x == 1 && y == 1){
			cout << "YES\n";
			return;
		}
		if(el == 'U') y++;
		if(el == 'D') y--;
		if(el == 'R') x++;
		if(el == 'L') x--;
	}
	if(x == 1 && y == 1){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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