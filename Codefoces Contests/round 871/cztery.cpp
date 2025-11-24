#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

bool subsolve(int a, int b){
	if(b > a) return false;
	if(b ==a) return true;
	if(a % 3 != 0) return false;
	bool res = false;
	res |= subsolve(a/3, b);
	res |= subsolve(a/3 * 2, b);
	return res;
}

void solve(){
	int a,b;
	cin >> a >> b;
	bool res = subsolve(a, b);
	if(res){
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
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 