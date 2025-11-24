#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int res = INT_MAX;
	for(int i = 1; i <= 100; i++){
		res = min(res, abs(a-i) + abs(b-i) + abs(c-i));
	}
	cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 