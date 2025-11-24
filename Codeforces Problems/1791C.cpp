#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	string text;
	cin >> text;
	for(int i = 0; i < n/2; i++){
		if((text[i] == '0' && text[n-1-i] == '1') || (text[i] == '1' && text[n-1-i] == '0')){
			continue;
		}
		else{
			cout << n - 2 * i << endl;
			return;
		}
	}
	if(n&1)
		cout << 1 << endl;
	else
		cout << 0 << endl;
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