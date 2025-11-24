#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve(){
	int n;
	cin >> n;
	cout << (n % 6 == 0 ? "YES" : "NO") << endl;;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
