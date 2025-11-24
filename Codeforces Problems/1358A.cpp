#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b;
	cin >> a >> b; 
	cout << min(a/2 * b + (b+1)/2 * (a&1 ? 1 : 0) , b/2 * a + (a+1)/2  * (b&1 ? 1 : 0)) << endl;
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