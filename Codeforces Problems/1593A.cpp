#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	cout << max(0ll, max(b,c) - a + 1) << " " << max(0ll, max(a,c) - b + 1) << " " << max(0ll, max(a,b) - c + 1) << endl;
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