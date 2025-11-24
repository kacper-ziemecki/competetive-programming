#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	cout << (text[0] - '0') + (text[2] - '0') << endl;
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