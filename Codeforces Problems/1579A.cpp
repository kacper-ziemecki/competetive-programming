#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	ll a = 0, b = 0, c = 0;
	for(auto el : text){
		if(el == 'A') a++;
		if(el == 'B') b++;
		if(el == 'C') c++;
	}
	cout << (b == a+c ? "YES\n" : "NO\n");
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