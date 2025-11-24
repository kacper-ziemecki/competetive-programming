#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	if(n == 2){
		cout << "NO\n";
		return;
	}
	cout << (n&1 ? "NO\n" : "YES\n");
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin); 
	solve();	
} 